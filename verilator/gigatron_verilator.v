module top(VGA_R,VGA_B,VGA_G,VGA_HS,VGA_VS,VGA_DE,reset,clk_sys,clk_vid,clk_app,ioctl_upload,ioctl_download,ioctl_addr,ioctl_dout,ioctl_din,ioctl_index,ioctl_wait,ioctl_wr);

   input clk_sys/*verilator public_flat*/;
   input clk_vid/*verilator public_flat*/;
   input clk_app/*verilator public_flat*/;
   input reset/*verilator public_flat*/;

   output [7:0] VGA_R/*verilator public_flat*/;
   output [7:0] VGA_G/*verilator public_flat*/;
   output [7:0] VGA_B/*verilator public_flat*/;
   
   output VGA_HS/*verilator public_flat*/;
   output VGA_VS/*verilator public_flat*/;
   output VGA_DE/*verilator public_flat*/;
   
   input        ioctl_upload;
   input        ioctl_download;
   input        ioctl_wr;
   input [24:0] ioctl_addr;
   input [7:0] ioctl_dout;
   output [7:0] ioctl_din;
   input [7:0]  ioctl_index;
   output  reg  ioctl_wait=1'b0;
   
reg [10:0] ps2_key/*verilator public_flat*/;
reg [31:0] joystick/*verilator public_flat*/;

////////////////////////////  HPS I/O  //////////////////////////////////

wire [1:0] buttons;
wire [31:0] status;
wire        img_mounted;
wire        img_readonly;
wire [63:0] img_size;
wire        ioctl_download;
wire [24:0] ioctl_addr;
wire [7:0]  ioctl_dout;
wire        ioctl_wr;
wire [7:0]  ioctl_index;

wire vsync_n;
wire hsync_n;
wire [1:0] red;
wire [1:0] green;
wire [1:0] blue;
wire hblank, vblank;
wire [7:0] gigatron_output_port;
wire [7:0] gigatron_extended_output_port;

wire famicom_pulse;
wire famicom_latch;
wire famicom_data;

// verilator lint_off PINMISSING
Gigatron_Shell gigatron_shell(
    .fpga_clock(clk_sys), // 50Mhz FPGA clock
    .vga_clock(clk_vid),      // 25Mhz VGA clock
    .clock(clk_app), // 6.25Mhz Gigatron clock
    .reset(reset),
    .run(1'b1),

    .gigatron_output_port(gigatron_output_port),
    //.gigatron_extended_output_port(gigatron_extended_output_port),
    
    //
    // These signals are from the Famicom serial game controller.
    //
    .famicom_pulse(famicom_pulse), // output
    .famicom_latch(famicom_latch), // output
    .famicom_data(famicom_data), // input

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
    ////    .led5(gigatron_led5),
    ////    .led6(gigatron_led6),
    ////    .led7(gigatron_led7),
    ////    .led8(gigatron_led8),

    //// 16 bit LPCM audio output from the Gigatron.
    .audio_dac(AUDIO_L),
    ////    // Digital volume control with range 0 - 11.
    .digital_volume_control(4'd11),

    //// Signals from user interface to select program to load
    .loader_go(buttons[1]),  // input, true when user select load
    .loader_program_select(4'd0)
    //.loader_active(application_active) // output
);	
// verilator lint_on PINMISSING
wire [15:0] AUDIO_L;
wire [15:0] AUDIO_R = AUDIO_L;

//////////////////////////////  VIDEO  ////////////////////////////////////
assign VGA_R={red,red,red,red};
assign VGA_G={green,green,green,green};
assign VGA_B={blue,blue,blue,blue};

assign VGA_HS = ~hsync_n;
assign VGA_VS = ~vsync_n;
assign VGA_DE = ~(VGA_HS|VGA_VS);


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
	ascii_code[4], ascii_code[5], ascii_code[6], ascii_code[7]
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

