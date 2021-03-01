//
//
//

`define SDL_DISPLAY 
//`define USE_VGA

module top(VGA_R,VGA_B,VGA_G,VGA_HS,VGA_VS,reset,clk_sys,clk_vid,clk_app,ioctl_upload,ioctl_download,ioctl_addr,ioctl_dout,ioctl_din,ioctl_index,ioctl_wait,ioctl_wr);

   input clk_sys/*verilator public_flat*/;
   input clk_vid/*verilator public_flat*/;
   input clk_app/*verilator public_flat*/;
   input reset/*verilator public_flat*/;

   output [7:0] VGA_R/*verilator public_flat*/;
   output [7:0] VGA_G/*verilator public_flat*/;
   output [7:0] VGA_B/*verilator public_flat*/;
   
   output VGA_HS/*verilator public_flat*/;
   output VGA_VS/*verilator public_flat*/;
   
   input        ioctl_upload;
   input        ioctl_download;
   input        ioctl_wr;
   input [24:0] ioctl_addr;
   input [7:0] ioctl_dout;
   output [7:0] ioctl_din;
   input [7:0]  ioctl_index;
   output  reg  ioctl_wait=1'b0;
   

//reg clk_app;
//reg [2:0] clk_app_counter;
//always @(posedge clk_sys) begin
    //clk_app_counter <= clk_app_counter+1;
    //if (clk_app_counter==0) begin
        //clk_app=~clk_app;
    //end
//end

//wire reset_n;
//Reset_Delay reset_generator(
    //.iCLK(clk_sys),
    //.oRESET(reset_n) // output
//);
//assign reset = ~reset_n;

wire [3:0] led/*verilator public_flat*/;

reg [7:0]  trakball/*verilator public_flat*/;
reg [7:0]  joystick/*verilator public_flat*/;
reg [7:0]  sw1/*verilator public_flat*/;
reg [7:0]  sw2/*verilator public_flat*/;
reg [9:0]  playerinput/*verilator public_flat*/;

   
//-------------------------------------------------------------------

//wire cart_download = ioctl_download & (ioctl_index != 8'd0);
//wire bios_download = ioctl_download & (ioctl_index == 8'd0);


//reg old_cart_download;
//reg initial_pause = 1'b1;

//always @(posedge clk_sys) begin
	//old_cart_download <= cart_download;
	//if (old_cart_download & ~cart_download) initial_pause <= 1'b0;
//end

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

wire [15:0] joy0,joy1;


//reg [7:0]RR=8'b0;
//reg [7:0]GG=8'b0;
//reg [7:0]BB=8'b11111111;
//assign VGA_R=RR;
//assign VGA_G=GG;
//assign VGA_B=BB;
/*wire [7:0] VGA_R2;
wire [7:0] VGA_G2;
wire [7:0] VGA_B2;
always @(posedge clk_sys) begin
	$display("vga: %x %x %x", VGA_R,VGA_G,VGA_B);
end*/

//always @(posedge clk_vid) begin
	//$display("vga: %x %x %x %b %b", VGA_R,VGA_G,VGA_B,VGA_HS,VGA_VS);
//end

//always @(posedge clk_sys) begin
    //$display("clocks: %b %b %b", clk_sys, clk_vid, clk_app);
    //$display("output: %d", gigatron_output_port);
    //$display("reset: %b", reset);
//end
//always @(negedge clk_sys) begin
    //$display("clocks: %b %b %b", clk_sys, clk_vid, clk_app);
//end



wire vsync_n;
wire hsync_n;
wire [1:0] red;
wire [1:0] green;
wire [1:0] blue;
//wire hblank, vblank;
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
    .gigatron_extended_output_port(gigatron_extended_output_port),
    
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
    //.hblank(hblank),
    //.vblank(vblank),

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
//assign red = gigatron_output_port[1:0];
//assign green = gigatron_output_port[3:2];
//assign blue = gigatron_output_port[5:4];
//assign hsync_n = gigatron_output_port[6:6];
//assign vsync_n = gigatron_output_port[7:7];
assign VGA_R={red,red,red,red};
assign VGA_G={green,green,green,green};
assign VGA_B={blue,blue,blue,blue};

assign VGA_HS = ~hsync_n;
assign VGA_VS = ~vsync_n;
//assign HBlank = hblank;
//assign VBlank = vblank;
//wire ce_pix = 1'b1;

endmodule


//module	Reset_Delay(iCLK,oRESET);
//input		iCLK;
//output reg	oRESET;
//reg	[19:0]	Cont;

//always@(posedge iCLK)
//begin
    //if(Cont != 20'hFFFFF)
    //begin
        //Cont	<=	Cont + 10'h1;
        //oRESET	<=	1'b0;
    //end
    //else
    //oRESET	<=	1'b1;
//end
//endmodule
