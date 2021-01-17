module verilator_top(
    input clk_sys,
    input clk_video,
    input clk_app,
    input reset,
    input loader_go,
    output VGA_HS, VGA_VS, VGA_DE,
    output [1:0] VGA_R, VGA_G, VGA_B,
    output [9:0] hpos, vpos,
    output [15:0] AUDIO_L
);

wire HBlank;
wire HSync;
wire VBlank;
wire VSync;
wire ce_pix;
wire [7:0] video;

assign ce_pix = 1'b1;

 Gigatron_Shell gigatron_shell(

    .fpga_clock(clk_sys), // 50Mhz FPGA clock

    .vga_clock(vga_clock),      // 25Mhz VGA clock from the PLL

    .clock(application_clock), // 6.25Mhz Gigatron clock from the PLL

    .reset(reset),

    .run(1'b1),

/* verilator lint_off PINMISSING */

//    .gigatron_output_port(gigatron_output_port),

//    .gigatron_extended_output_port(gigatron_extended_output_port),

//

//    //

//    // These signals are from the Famicom serial game controller.

//    //

//    .famicom_pulse(famicom_pulse), // output

//    .famicom_latch(famicom_latch), // output

//    .famicom_data(famicom_data),   // input



    // Raw VGA signals from the Gigatron

    .hsync_n(hsync_n),

    .vsync_n(vsync_n),

    .red(VGA_R),

    .green(VGA_G),

    .blue(VGA_B),

    .hblank(HBlank),

    .vblank(VBlank),



    //

    // Write output to external framebuffer

    //

    // Note: Gigatron outputs its 6.25Mhz clock as the clock

    // to synchronize these signals.

    //

    // The output is standard 8 bit true color with RRRGGGBB.

    //

    // https://en.wikipedia.org/wiki/8-bit_color

    //

//    .framebuffer_write_clock(framebuffer_write_clock),

//    .framebuffer_write_signal(framebuffer_write_signal),

//    .framebuffer_write_address(framebuffer_write_address),

//    .framebuffer_write_data(framebuffer_write_data),



    // BlinkenLights

//    .led5(gigatron_led5),

//    .led6(gigatron_led6),

//    .led7(gigatron_led7),

//    .led8(gigatron_led8),



    // 16 bit LPCM audio output from the Gigatron.

    .audio_dac(AUDIO_L),



//    // Digital volume control with range 0 - 11.

    .digital_volume_control(4'd11),

//

//    // Signals from user interface to select program to load

    .loader_go(buttons[1]),  // input, true when user select load

    .loader_program_select(4'd0)

//  .loader_active(application_active) // output
/* verilator lint_on PINMISSING */
  );	

  
wire hsync_n;
wire vsync_n;
assign VGA_HS = ~hsync_n;
assign VGA_VS = ~vsync_n;
assign VGA_DE = ~(HBlank | VBlank);
endmodule
