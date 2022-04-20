module top(VGA_R,VGA_B,VGA_G,VGA_HS,VGA_VS,VGA_DE,VGA_HB,VGA_VB,CE_PIXEL,AUDIO_L,AUDIO_R,ps2_key,joystick_0,joystick_1,joystick_2,joystick_3,menu,reset,clk_sys,ioctl_upload,ioctl_download,ioctl_addr,ioctl_dout,ioctl_din,ioctl_index,ioctl_wait,ioctl_wr);

   input clk_sys;
   input reset;

   output [7:0] VGA_R;
   output [7:0] VGA_G;
   output [7:0] VGA_B;
   
   output VGA_HS;
   output VGA_VS;
   output VGA_DE;
   output VGA_HB;
   output VGA_VB;
   output CE_PIXEL;
   
   output [15:0] AUDIO_L;
   output [15:0] AUDIO_R;


   input        ioctl_upload;
   input        ioctl_download;
   input        ioctl_wr;
   input [24:0] ioctl_addr;
   input [7:0] ioctl_dout;
   output [7:0] ioctl_din;
   input [7:0]  ioctl_index;
   output  reg  ioctl_wait=1'b0;
   
   input reg [10:0] ps2_key;
   input reg [31:0] joystick_0;
   input reg [31:0] joystick_1;
   input reg [31:0] joystick_2;
   input reg [31:0] joystick_3;
   input reg menu;

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

reg clk_app;
reg clk_vid;

reg clk_vid_divider;
reg [2:0] clk_app_divider;
always @(posedge clk_sys) begin
  if (clk_vid_divider==1'd1) begin
    clk_vid <= ~clk_vid;
  end
  clk_vid_divider <= clk_vid_divider + 1'd1;
end 
always @(posedge clk_sys) begin
  if (clk_app_divider==3'd7) begin
    clk_app <= ~clk_app;
  end
  clk_app_divider <= clk_app_divider + 3'd1;
end 

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
assign AUDIO_R = AUDIO_L;

//////////////////////////////  VIDEO  ////////////////////////////////////
assign VGA_R={red,red,red,red};
assign VGA_G={green,green,green,green};
assign VGA_B={blue,blue,blue,blue};

assign VGA_HS = ~hsync_n;
assign VGA_VS = ~vsync_n;
assign VGA_DE = ~(hblank|vblank);
assign VGA_HB = hblank;
assign VGA_VB = vblank;
//assign CE_PIXEL = 1'b1;
assign CE_PIXEL = clk_vid;

////////////////////////////  INPUT  //////////////////////////////////////

reg [7:0] joypad_bits;
reg joypad_clock, last_joypad_clock;
reg joypad_out;

wire [7:0] nes_joy_A = { 
    joystick_0[0], joystick_0[1], joystick_0[2], joystick_0[3],
    joystick_0[7], joystick_0[6], joystick_0[5], joystick_0[4] 
};

reg [7:0] ascii_code;

wire [7:0] ascii_bitmap = {
	ascii_code[0], ascii_code[1], ascii_code[2], ascii_code[3],
	ascii_code[4], ascii_code[5], ascii_code[6], ascii_code[7]
};

wire discard;

Keyboard keyboard(
    .ps2_key(ps2_key),
    .pulse(famicom_pulse),
    .ascii_code(ascii_code),
    .kb_lang(3'd0),
    .caps_lock(discard),
    .reset(reset)
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

