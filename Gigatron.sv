//============================================================================
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write to the Free Software Foundation, Inc.,
//  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//============================================================================

module emu
(
	//Master input clock
	input         CLK_50M,

	//Async reset from top-level module.
	//Can be used as initial reset.
	input         RESET,

	//Must be passed to hps_io module
	inout  [45:0] HPS_BUS,

	//Base video clock. Usually equals to CLK_SYS.
	output        CLK_VIDEO,

	//Multiple resolutions are supported using different CE_PIXEL rates.
	//Must be based on CLK_VIDEO
	output        CE_PIXEL,

	//Video aspect ratio for HDMI. Most retro systems have ratio 4:3.
	output [11:0] VIDEO_ARX,
	output [11:0] VIDEO_ARY,

	output  [7:0] VGA_R,
	output  [7:0] VGA_G,
	output  [7:0] VGA_B,
	output        VGA_HS,
	output        VGA_VS,
	output        VGA_DE,    // = ~(VBlank | HBlank)
	output        VGA_F1,
	output [1:0]  VGA_SL,
	output        VGA_SCALER, // Force VGA scaler
	
	input  [11:0] HDMI_WIDTH,
	input  [11:0] HDMI_HEIGHT,

	/*
	// Use framebuffer from DDRAM (USE_FB=1 in qsf)
	// FB_FORMAT:
	//    [2:0] : 011=8bpp(palette) 100=16bpp 101=24bpp 110=32bpp
	//    [3]   : 0=16bits 565 1=16bits 1555
	//    [4]   : 0=RGB  1=BGR (for 16/24/32 modes)
	//
	// FB_STRIDE either 0 (rounded to 256 bytes) or multiple of 16 bytes.
	output        FB_EN,
	output  [4:0] FB_FORMAT,
	output [11:0] FB_WIDTH,
	output [11:0] FB_HEIGHT,
	output [31:0] FB_BASE,
	output [13:0] FB_STRIDE,
	input         FB_VBL,
	input         FB_LL,
	output        FB_FORCE_BLANK,

	// Palette control for 8bit modes.
	// Ignored for other video modes.
	output        FB_PAL_CLK,
	output  [7:0] FB_PAL_ADDR,
	output [23:0] FB_PAL_DOUT,
	input  [23:0] FB_PAL_DIN,
	output        FB_PAL_WR,
	*/

	output        LED_USER,  // 1 - ON, 0 - OFF.

	// b[1]: 0 - LED status is system status OR'd with b[0]
	//       1 - LED status is controled solely by b[0]
	// hint: supply 2'b00 to let the system control the LED.
	output  [1:0] LED_POWER,
	output  [1:0] LED_DISK,

	// I/O board button press simulation (active high)
	// b[1]: user button
	// b[0]: osd button
	output  [1:0] BUTTONS,

	input         CLK_AUDIO, // 24.576 MHz
	output [15:0] AUDIO_L,
	output [15:0] AUDIO_R,
	output        AUDIO_S,   // 1 - signed audio samples, 0 - unsigned
	output  [1:0] AUDIO_MIX, // 0 - no mix, 1 - 25%, 2 - 50%, 3 - 100% (mono)

	//ADC
	inout   [3:0] ADC_BUS,

	//SD-SPI
	output        SD_SCK,
	output        SD_MOSI,
	input         SD_MISO,
	output        SD_CS,
	input         SD_CD,

	//High latency DDR3 RAM interface
	//Use for non-critical time purposes
	output        DDRAM_CLK,
	input         DDRAM_BUSY,
	output  [7:0] DDRAM_BURSTCNT,
	output [28:0] DDRAM_ADDR,
	input  [63:0] DDRAM_DOUT,
	input         DDRAM_DOUT_READY,
	output        DDRAM_RD,
	output [63:0] DDRAM_DIN,
	output  [7:0] DDRAM_BE,
	output        DDRAM_WE,

	//SDRAM interface with lower latency
	output        SDRAM_CLK,
	output        SDRAM_CKE,
	output [12:0] SDRAM_A,
	output  [1:0] SDRAM_BA,
	inout  [15:0] SDRAM_DQ,
	output        SDRAM_DQML,
	output        SDRAM_DQMH,
	output        SDRAM_nCS,
	output        SDRAM_nCAS,
	output        SDRAM_nRAS,
	output        SDRAM_nWE,

	input         UART_CTS,
	output        UART_RTS,
	input         UART_RXD,
	output        UART_TXD,
	output        UART_DTR,
	input         UART_DSR,

	// Open-drain User port.
	// 0 - D+/RX
	// 1 - D-/TX
	// 2..6 - USR2..USR6
	// Set USER_OUT to 1 to read from USER_IN.
	input   [6:0] USER_IN,
	output  [6:0] USER_OUT,

	input         OSD_STATUS
);

///////// Default values for ports not used in this core /////////

assign ADC_BUS  = 'Z;
assign USER_OUT = '1;
assign {UART_RTS, UART_TXD, UART_DTR} = 0;
assign {SD_SCK, SD_MOSI, SD_CS} = 'Z;
assign {SDRAM_DQ, SDRAM_A, SDRAM_BA, SDRAM_CLK, SDRAM_CKE, SDRAM_DQML, SDRAM_DQMH, SDRAM_nWE, SDRAM_nCAS, SDRAM_nRAS, SDRAM_nCS} = 'Z;
assign {DDRAM_CLK, DDRAM_BURSTCNT, DDRAM_ADDR, DDRAM_DIN, DDRAM_BE, DDRAM_RD, DDRAM_WE} = '0;  

assign VGA_SL = 0;
assign VGA_F1 = 0;
assign VGA_SCALER = 0;

assign AUDIO_S = 0;
assign AUDIO_MIX = 3;

assign BUTTONS = 0;

//////////////////////////////  HPS  ////////////////////////////////////

wire [1:0] ar = status[9:8];

assign VIDEO_ARX = (!ar) ? 12'd4 : (ar - 1'd1);
assign VIDEO_ARY = (!ar) ? 12'd3 : 12'd0;

`include "build_id.v" 
localparam CONF_STR = {
	"Gigatron;;",
	"-;",
	"O89,Aspect ratio,Original,Full Screen,[ARC1],[ARC2];",
	"-;",
	"-;",
	"T0,Reset;",
	"R0,Reset and close OSD;",
	"J1,A,B,Select,Start;",
	"jn,A,B,Select,Start;",
	"V,v",`BUILD_DATE 
};

wire forced_scandoubler;
wire  [1:0] buttons;
wire [31:0] status;
wire [10:0] ps2_key;
wire [15:0] joystick;

hps_io #(.STRLEN($size(CONF_STR)>>3)) hps_io
(
	.clk_sys(clk_sys),
	.HPS_BUS(HPS_BUS),
	.EXT_BUS(),
	.gamma_bus(),

	.conf_str(CONF_STR),
	.forced_scandoubler(forced_scandoubler),

	.buttons(buttons),
	.status(status),
	.status_menumask({status[5]}),
	
	.joystick_0(joystick),
	.ps2_key(ps2_key)
);

///////////////////////   CLOCKS   ///////////////////////////////

wire clk_sys;
wire clk_vid;
wire clk_app;
pll pll
(
	.refclk(CLK_50M),
	.rst(0),
	.outclk_0(clk_sys),
	.outclk_1(clk_vid),
	.outclk_2(clk_app)
);

wire reset = RESET | status[0];

//////////////////////////////  MAIN CORE CONNECTIONS  ////////////////////////////////////

wire vsync_n;
wire hsync_n;
wire [1:0] red;
wire [1:0] green;
wire [1:0] blue;
wire hblank, vblank;

wire [7:0] gigatron_output_port;
wire [15:0] audio;

wire famicom_latch;
wire famicom_pulse;
wire famicom_data;

Gigatron_Shell gigatron_shell(
    .fpga_clock(clk_sys), // 50Mhz FPGA clock
    .vga_clock(clk_vid),      // 25Mhz VGA clock from the PLL
    .clock(clk_app), // 6.25Mhz Gigatron clock from the PLL
    .reset(reset),
    .run(1'b1),

    .gigatron_output_port(gigatron_output_port),
    //.gigatron_extended_output_port(gigatron_extended_output_port),
    
    //
    // These signals are from the Famicom serial game controller.
    //
    .famicom_pulse(famicom_pulse), // output
    .famicom_latch(famicom_latch), // output
    .famicom_data(famicom_data),   // input

    //// Raw VGA signals from the Gigatron

    .hsync_n(hsync_n),
    .vsync_n(vsync_n),
    .red(red),
    .green(green),
    .blue(blue),
    .hblank(hblank),
    .vblank(vblank),

    ////
    //// Write output to external framebuffer
    ////
    //// Note: Gigatron outputs its 6.25Mhz clock as the clock
    //// to synchronize these signals.
    ////
    //// The output is standard 8 bit true color with RRRGGGBB.
    ////
    //// https://en.wikipedia.org/wiki/8-bit_color
    ////
    ////    .framebuffer_write_clock(framebuffer_write_clock),
    ////    .framebuffer_write_signal(framebuffer_write_signal),
    ////    .framebuffer_write_address(framebuffer_write_address),
    ////    .framebuffer_write_data(framebuffer_write_data),

    //// BlinkenLights
        .led5(LED_POWER[0]),
        .led6(LED_DISK[0]),
        .led7(LED_USER),
    ////    .led8(gigatron_led8),

    //// 16 bit LPCM audio output from the Gigatron.
    .audio_dac(audio),
    ////    // Digital volume control with range 0 - 11.
    .digital_volume_control(4'd11),

    //// Signals from user interface to select program to load
    //.loader_go(buttons[1]),  // input, true when user select load
    .loader_program_select(4'd0)
    //.loader_active(application_active) // output
);	

//////////////////////////////  VIDEO  ////////////////////////////////////

assign VGA_R={red,red,red,red};
assign VGA_G={green,green,green,green};
assign VGA_B={blue,blue,blue,blue};

assign VGA_VS = ~vsync_n;
assign VGA_HS = ~hsync_n;
assign VGA_DE = ~(hblank|vblank);
assign CE_PIXEL = 1'b1;
assign CLK_VIDEO = clk_vid;

//////////////////////////////  LEDS  ////////////////////////////////////

assign LED_DISK[1] = 1;
assign LED_POWER[1] = 1;

//////////////////////////////  AUDIO  ////////////////////////////////////
assign AUDIO_L = audio;
assign AUDIO_R = audio;

////////////////////////////  INPUT  //////////////////////////////////////

reg [7:0] joypad_bits;
reg joypad_clock, last_joypad_clock;
reg joypad_out;

wire [7:0] nes_joy_A = { 
    joystick[0], joystick[1], joystick[2], joystick[3],
    joystick[7], joystick[6], joystick[5], joystick[4] 
};

reg [7:0] ascii_code;

wire [7:0] ascii_bitmap = {
	ascii_code[0], ascii_code[1], ascii_code[2], ascii_code[3],
	ascii_code[4], ascii_code[5], ascii_code[6], ascii_code[7],
};

Keyboard keyboard(
    .ps2_key(ps2_key),
    .pulse(famicom_pulse),
    .ascii_code(ascii_code)
);

always @(posedge clk_sys) begin
	if (reset) begin
		joypad_bits <= 0;
		last_joypad_clock <= 0;
	end else begin
		if (joypad_out) begin
			joypad_bits  <= ~(nes_joy_A | ~ascii_bitmap);
		end
		if (!joypad_clock && last_joypad_clock) begin
			joypad_bits <= {1'b0, joypad_bits[7:1]};
		end
		last_joypad_clock <= joypad_clock;
	end
end

assign joypad_out=famicom_latch;
assign joypad_clock=~famicom_pulse;
assign famicom_data=joypad_bits[0];


endmodule
