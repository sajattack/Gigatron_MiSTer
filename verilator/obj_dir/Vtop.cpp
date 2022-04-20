// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VerilatedContext* Vtop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ioctl_upload = vlTOPp->ioctl_upload;
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__ioctl_dout = vlTOPp->ioctl_dout;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_clock 
        = vlTOPp->clk_sys;
    vlTOPp->top__DOT__clk_vid = vlTOPp->clk_vid;
    vlTOPp->top__DOT__clk_app = vlTOPp->clk_app;
    vlTOPp->top__DOT__reset = vlTOPp->reset;
    vlTOPp->top__DOT__clk_sys = vlTOPp->clk_sys;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__vga_clock 
        = vlTOPp->top__DOT__clk_vid;
    vlTOPp->top__DOT__gigatron_shell__DOT__clock = vlTOPp->top__DOT__clk_app;
    vlTOPp->top__DOT__keyboard__DOT__reset = vlTOPp->top__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__reset = vlTOPp->top__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__fpga_clock 
        = vlTOPp->top__DOT__clk_sys;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__output_framebuffer_write_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__vga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__gigatron_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__gigatron_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__gigatron_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__gigatron_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__gigatron_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__gigatron_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__gigatron_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__gigatron_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__gigatron_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__gigatron_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__fpga_clock;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reset 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reset;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__fpga_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__fpga_clock;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vtableidx1;
    CData/*7:0*/ __Vdly__top__DOT__joypad_bits;
    CData/*4:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state;
    CData/*4:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state;
    CData/*3:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state;
    CData/*3:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state;
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length;
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length;
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred;
    CData/*3:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state;
    CData/*3:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state;
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum;
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output;
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer;
    CData/*2:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state;
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value;
    CData/*3:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter;
    CData/*7:0*/ __Vdlyvval__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0;
    CData/*0:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal;
    SData/*15:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address;
    SData/*8:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length;
    SData/*15:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address;
    SData/*15:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent;
    SData/*15:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address;
    SData/*15:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent;
    SData/*15:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent;
    SData/*14:0*/ __Vdlyvdim0__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0;
    // Body
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal;
    __Vdly__top__DOT__joypad_bits = vlTOPp->top__DOT__joypad_bits;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state;
    __Vdlyvset__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0 = 0U;
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal = 0U;
    } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal = 0U;
    } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal = 1U;
    }
    if (vlTOPp->reset) {
        __Vdly__top__DOT__joypad_bits = 0U;
    } else {
        if (vlTOPp->top__DOT__joypad_out) {
            __Vdly__top__DOT__joypad_bits = (0xffU 
                                             & (~ ((IData)(vlTOPp->top__DOT__nes_joy_A) 
                                                   | (~ (IData)(vlTOPp->top__DOT__ascii_bitmap)))));
        }
        if (((~ (IData)(vlTOPp->top__DOT__joypad_clock)) 
             & (IData)(vlTOPp->top__DOT__last_joypad_clock))) {
            __Vdly__top__DOT__joypad_bits = (0x7fU 
                                             & ((IData)(vlTOPp->top__DOT__joypad_bits) 
                                                >> 1U));
        }
    }
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_request_ack = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_output_port = 0U;
    } else if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state))) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 0U;
            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request)))) {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_request_ack = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 0U;
            }
        } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state))) {
            if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_latch) {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_output_port 
                    = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value) 
                             >> (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter))));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 4U;
            }
        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_latch)))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 2U;
        }
    } else if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state))) {
        if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state))) {
            if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_pulse) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter 
                    = (0xfU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter) 
                               - (IData)(1U)));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 1U;
            }
        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_pulse)))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 3U;
        }
    } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state))) {
        if ((0xfU != (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter))) {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_output_port 
                = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value) 
                         >> (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter))));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 2U;
        } else {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_request_ack = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state = 6U;
        }
    } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent 
            = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent)));
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter 
            = (0xfU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_count) 
                       - (IData)(1U)));
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state 
            = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_frame_start)
                ? 5U : 1U);
    }
    if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_write) {
        __Vdlyvval__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_data;
        __Vdlyvset__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_address;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal;
    vlTOPp->top__DOT__joypad_bits = __Vdly__top__DOT__joypad_bits;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__bits_state;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_send_bits_value;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_bits_counter;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_total_bytes_sent;
    if (__Vdlyvset__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem[__Vdlyvdim0__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem__v0;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_signal 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_signal;
    vlTOPp->top__DOT__last_joypad_clock = ((~ (IData)(vlTOPp->reset)) 
                                           & (IData)(vlTOPp->top__DOT__joypad_clock));
    vlTOPp->top__DOT__famicom_data = (1U & (IData)(vlTOPp->top__DOT__joypad_bits));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_output_port;
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_request_ack = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_rom_address = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_frame_start = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_count = 0U;
    } else if ((8U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0U;
                } else {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
                        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum;
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
                        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output;
                    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 1U;
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 1U;
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 7U;
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
                    = (0xffU & ((IData)(0x4cU) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum)));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
                    = (0xffU & ((IData)(0x4cU) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output)));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0xeU;
            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request)))) {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_request_ack = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0U;
            }
        } else if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 1U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 7U;
            } else {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
                    = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum) 
                                + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data)));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
                    = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output) 
                                + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data)));
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value 
                    = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0xbU;
            }
        } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0xaU;
        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__send_bits_request_ack)))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state 
                = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state;
        }
    } else if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
                if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__send_bits_request_ack) {
                    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 0U;
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 8U;
                }
            } else {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_request_ack = 1U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0xcU;
            }
        } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
            if ((0U == (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer))) {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value 
                    = (0xffU & (- (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output)));
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 1U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 6U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 7U;
            } else {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer 
                    = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer) 
                                - (IData)(1U)));
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_rom_address 
                    = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__frame_loader_rom_address)));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 5U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 9U;
            }
        } else {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_rom_address 
                = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address;
            if ((0U == (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length))) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 5U;
            } else {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer 
                    = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length) 
                                - (IData)(1U)));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 5U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 9U;
            }
        }
    } else if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
        if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
                = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum) 
                            + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address)));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
                = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output) 
                            + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address)));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value 
                = (0xffU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 4U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 7U;
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
                = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum) 
                            + ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address) 
                               >> 8U)));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
                = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output) 
                            + ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address) 
                               >> 8U)));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_count = 8U;
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value 
                = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address) 
                            >> 8U));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 3U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 7U;
        }
    } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state))) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
            = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum) 
                        + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length)));
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
            = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output) 
                        + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length)));
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_frame_start = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_count = 6U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request = 1U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state = 2U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 7U;
    } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent 
            = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent)));
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_running_checksum_input;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_request_ack = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value = 0x4cU;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_rom_address = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_count = 8U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_frame_start = 1U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum = 0x67U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state = 0xdU;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_signal 
        = vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_signal;
    vlTOPp->top__DOT__gigatron_shell__DOT__famicom_data 
        = vlTOPp->top__DOT__famicom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__famicom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_state;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_next_state;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__loader_checksum;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_data_to_transfer;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_total_frames_sent;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__send_bits_request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__reg_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__output_framebuffer_write_signal 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_signal;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__famicom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__famicom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__famicom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__famicom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__request 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_request;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__frame_start 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_frame_start;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__value 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_value;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__number_of_bits 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_send_bits_count;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__send_bits_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__frame_loader_rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_rom_address;
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_request_ack = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_running_checksum_input = 0U;
    } else if ((8U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 0U;
        } else if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 0U;
        } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 0U;
        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request)))) {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_request_ack = 0U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 0U;
        }
    } else if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__send_frame_request_ack)))) {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state 
                        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state;
                }
            } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__send_frame_request_ack) {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 7U;
            }
        } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_request_ack = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 8U;
        } else {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state = 5U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 6U;
        }
    } else if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
        if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_request_ack = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 8U;
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address 
                = (0xffffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address) 
                              + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length)));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address 
                = (0xffffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address) 
                              + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length)));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_running_checksum_input 
                = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__running_checksum_output;
            if ((0U == (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length))) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 3U;
            } else {
                if ((0x3cU < (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length))) {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred 
                        = (0xffU & ((IData)(0x3cU) 
                                    + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred)));
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length 
                        = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length) 
                                    - (IData)(0x3cU)));
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length = 0x3cU;
                } else {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length 
                        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length;
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred 
                        = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred) 
                                    + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length)));
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length = 0U;
                }
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request = 1U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state = 2U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 6U;
            }
        }
    } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state))) {
        if ((0x3cU < (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length 
                = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length) 
                            - (IData)(0x3cU)));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length = 0x3cU;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred = 0x3cU;
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length 
                = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred 
                = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length = 0U;
        }
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request = 1U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state = 2U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state = 6U;
    } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent 
            = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent)));
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_request_ack = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length 
            = (0xffU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length));
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length 
            = (0xffU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length));
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_running_checksum_input = 0x67U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state 
            = ((0U == (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length))
                ? 4U : 1U);
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__famicom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__famicom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__frame_loader_rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__page_loader_rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__frame_loader_rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_state;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__loader_next_state;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_total_pages_sent;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_page_length_transferred;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__send_frame_request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__running_checksum_output 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__reg_running_checksum_output;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__output_port 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__famicom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__page_loader_rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__request 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_send_frame_request;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__running_checksum_input 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_running_checksum_input;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__request_data_rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__request_frame_remote_length 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_length;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__request_frame_remote_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_current_frame_remote_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__send_frame_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__running_checksum_output 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__running_checksum_output;
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_request_ack = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request = 0U;
    } else if ((0x10U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
        if ((8U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
            if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
                if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request)))) {
                            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_request_ack = 0U;
                            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0U;
                        }
                    } else {
                        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0U;
                    }
                } else {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0U;
                }
            } else {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0U;
            }
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0U;
        }
    } else if ((8U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0U;
        } else if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__send_page_request_ack)))) {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state 
                        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state;
                }
            } else {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_request_ack = 1U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0x1fU;
            }
        } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address 
                = ((0xff00U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address)) 
                   | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length = 0U;
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state = 0xaU;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 5U;
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
                = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address)));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address 
                = ((0xffU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address)) 
                   | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data) 
                      << 8U));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 9U;
        }
    } else if ((4U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 2U;
            } else {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
                    = (0xffffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address) 
                                  + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length)));
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 7U;
            }
        } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
            if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__send_page_request_ack) {
                vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 0xbU;
            }
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
                = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address)));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length 
                = ((0U == (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data))
                    ? 0x100U : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request = 1U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state = 6U;
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 5U;
        }
    } else if ((2U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
        if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
                = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address)));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address 
                = ((0xff00U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address)) 
                   | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 4U;
        } else if (((0U != (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address)) 
                    & (0U == (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data)))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
                = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address)));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 8U;
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
                = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address)));
            vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address 
                = ((0xffU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address)) 
                   | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data) 
                      << 8U));
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 3U;
        }
    } else if ((1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state))) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 7U;
    } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_request_ack = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state = 1U;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_state;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__loader_next_state;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__send_page_request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__reg_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__request_page_remote_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__request_page_remote_length 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_current_page_remote_length;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__send_page_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__request 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__request_data_rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_address 
        = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_send_page_request)
            ? (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__page_loader_rom_address)
            : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_rom_address));
    __Vtableidx1 = (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish_request_ack) 
                     << 4U) | ((8U & ((IData)(vlTOPp->top__DOT__buttons) 
                                      << 2U)) | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__loader_state) 
                                                  << 1U) 
                                                 | (IData)(vlTOPp->reset))));
    if ((1U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__loader_state 
            = vlTOPp->__Vtable1_top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__loader_state
            [__Vtableidx1];
    }
    if ((2U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request 
            = vlTOPp->__Vtable1_top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request
            [__Vtableidx1];
    }
    if ((4U & vlTOPp->__Vtablechg1[__Vtableidx1])) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_loader_active 
            = vlTOPp->__Vtable1_top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_loader_active
            [__Vtableidx1];
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__option_rom__DOT__address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__option_rom__DOT__reg_eeprom
        [(0x7fffU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_address))];
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish_request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__reg_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__option_rom__DOT__data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__rom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__request_ack 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish_request_ack;
    vlTOPp->top__DOT__gigatron_shell__DOT__loader_active 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_loader_active;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__request 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__loader_active 
        = vlTOPp->top__DOT__gigatron_shell__DOT__loader_active;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rom_data;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X;
    SData/*15:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC;
    // Body
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X;
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_cs = 1U;
    }
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC = 0U;
    } else {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC 
            = (0xffffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC)));
        if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_pl_n)))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC 
                = ((0xff00U & (IData)(__Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC)) 
                   | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus));
        }
        if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ph_n)))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC 
                = ((0xffU & (IData)(__Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC)) 
                   | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__Y) 
                      << 8U));
        }
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__D 
        = ((IData)(vlTOPp->reset) ? 0U : (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_data) 
                                                   >> 8U)));
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_xl_n)))) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X 
                = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu;
        }
        if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ix) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X 
                = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X)));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reg_output_port = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_dl_n)))) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reg_output_port 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__IR 
        = ((IData)(vlTOPp->reset) ? 0U : (0xffU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_data)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom__DOT__cs 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_cs;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__eeprom_cs 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_cs;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC;
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__Y = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_yl_n)))) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__Y 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu;
    }
    vlTOPp->top__DOT__gigatron_output_port = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reg_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__opcode 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__IR;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__condition 
        = (7U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__IR) 
                 >> 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__busmode 
        = (3U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__IR));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode 
        = (7U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__IR) 
                 >> 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr 
        = (7U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__IR) 
                 >> 5U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom__DOT__address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__eeprom_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_address;
    if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_cs) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom__DOT__data__out__out0 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom__DOT__reg_eeprom
            [vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_address];
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_output_port 
        = vlTOPp->top__DOT__gigatron_output_port;
    vlTOPp->top__DOT__red = (3U & (IData)(vlTOPp->top__DOT__gigatron_output_port));
    vlTOPp->top__DOT__green = (3U & ((IData)(vlTOPp->top__DOT__gigatron_output_port) 
                                     >> 2U));
    vlTOPp->top__DOT__blue = (3U & ((IData)(vlTOPp->top__DOT__gigatron_output_port) 
                                    >> 4U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_latch 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_output_port) 
                 >> 7U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_pulse 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_output_port) 
                 >> 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__serial_clock 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_output_port) 
                 >> 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ConditionDecoder__DOT__condition 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__condition;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__JumpDetector__DOT__condition 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__condition;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__JumpDetector__DOT__bf_n 
        = (1U & (~ (IData)((0U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__condition))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__BusAccessDecoder__DOT__busmode 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__busmode;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__de_n 
        = (1U & (~ (IData)((0U == (3U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__busmode))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ae_n 
        = (1U & (~ (IData)((2U == (3U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__busmode))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ie_n 
        = (1U & (~ (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__busmode) 
                     >> 1U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__busmode))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__oe_n 
        = (1U & (~ (IData)((1U == (3U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__busmode))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__address_mode 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__instr 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__st_n 
        = (1U & (~ (IData)((6U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__and_n 
        = (1U & (~ (IData)((1U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__xor_n 
        = (1U & (~ (IData)((3U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__ld_n 
        = (1U & (~ (IData)((0U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__add_n 
        = (1U & (~ (IData)((4U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__sub_n 
        = (1U & (~ (IData)((5U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__or_n 
        = (1U & (~ (IData)((2U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__bcc_n 
        = (1U & (~ (IData)((7U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom__DOT__data__out__out0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_output_port 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_output_port;
    vlTOPp->top__DOT__VGA_R = (0xffU & (((IData)(vlTOPp->top__DOT__red) 
                                         << 6U) | (
                                                   ((IData)(vlTOPp->top__DOT__red) 
                                                    << 4U) 
                                                   | (((IData)(vlTOPp->top__DOT__red) 
                                                       << 2U) 
                                                      | (IData)(vlTOPp->top__DOT__red)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__red = vlTOPp->top__DOT__red;
    vlTOPp->top__DOT__VGA_G = (0xffU & (((IData)(vlTOPp->top__DOT__green) 
                                         << 6U) | (
                                                   ((IData)(vlTOPp->top__DOT__green) 
                                                    << 4U) 
                                                   | (((IData)(vlTOPp->top__DOT__green) 
                                                       << 2U) 
                                                      | (IData)(vlTOPp->top__DOT__green)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__green = vlTOPp->top__DOT__green;
    vlTOPp->top__DOT__VGA_B = (0xffU & (((IData)(vlTOPp->top__DOT__blue) 
                                         << 6U) | (
                                                   ((IData)(vlTOPp->top__DOT__blue) 
                                                    << 4U) 
                                                   | (((IData)(vlTOPp->top__DOT__blue) 
                                                       << 2U) 
                                                      | (IData)(vlTOPp->top__DOT__blue)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__blue = vlTOPp->top__DOT__blue;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__famicom_latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__gigatron_famicom_latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__famicom_pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__gigatron_famicom_pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__de_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__de_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ae_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ae_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ie_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ie_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__oe_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__oe_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_oe 
        = (1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__oe_n)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__w_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__st_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1 
        = (1U & (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__or_n)) 
                  | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__xor_n))) 
                 | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__sub_n))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__ld_n)) 
                   | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__and_n))) 
                  | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__or_n))) 
                 | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__add_n))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al 
        = (1U & ((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__instr) 
                     >> 2U)) | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__bcc_n))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2 
        = (1U & (((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__ld_n)) 
                    | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__or_n))) 
                   | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__xor_n))) 
                  | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__add_n))) 
                 | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__bcc_n))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0 
        = (1U & ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__sub_n)) 
                 | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__bcc_n))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__bcc_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom__DOT__data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__eeprom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__io_in 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__io_in 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__output_port_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_output_port;
    vlTOPp->VGA_R = vlTOPp->top__DOT__VGA_R;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__red 
        = vlTOPp->top__DOT__gigatron_shell__DOT__red;
    vlTOPp->VGA_G = vlTOPp->top__DOT__VGA_G;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__green 
        = vlTOPp->top__DOT__gigatron_shell__DOT__green;
    vlTOPp->VGA_B = vlTOPp->top__DOT__VGA_B;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__blue 
        = vlTOPp->top__DOT__gigatron_shell__DOT__blue;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__famicom_latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__famicom_latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__gigatron_famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__famicom_pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__famicom_pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__gigatron_famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__BusAccessDecoder__DOT__de_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__de_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__BusAccessDecoder__DOT__ae_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ae_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__BusAccessDecoder__DOT__ie_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ie_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__BusAccessDecoder__DOT__oe_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__oe_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__oe 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_oe;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_oe 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_oe;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__w_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__w_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__al 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__j_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ConditionDecoder__DOT__j_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__j_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__JumpDetector__DOT__j_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_x_n 
        = (1U & (~ (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n))) 
                            & (4U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode)))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_y_n 
        = (1U & (~ (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n))) 
                            & (5U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode)))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_ac_n 
        = (1U & (~ (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n))) 
                            & (0U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode)))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ph_n 
        = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__JumpDetector__DOT__bf_n) 
           | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_out_n 
        = (1U & (~ (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n))) 
                            & (6U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode)))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0x_to_ac_n 
        = (1U & (~ (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n))) 
                            & (1U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode)))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yd_to_ac_n 
        = (1U & (~ (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n))) 
                            & (2U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode)))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_to_ac_n 
        = (1U & (~ (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n))) 
                            & (3U == (7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode)))))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_incr_to_out_n 
        = (1U & (~ ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n) 
                      & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode) 
                         >> 2U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode) 
                                    >> 1U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__address_mode))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__raw_output_red 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__red;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__raw_output_green 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__green;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__raw_output_blue 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__blue;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__famicom_latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__famicom_pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__ar1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__I1_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__I1_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__I1_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__I1_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__I2_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__I2_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__I2_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__I2_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__ar3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__I1_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__I1_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__I1_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__I1_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__I2_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__I2_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__I2_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__I2_3 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__al 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__E2_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__E2_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__E2_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__E2_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__E1_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__E1_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__E1_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__E1_N 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__al;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__ar2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__I1_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__I1_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__I1_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__I1_2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__I2_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__I2_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__I2_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__I2_1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__ar0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__I1_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__I1_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__I1_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__I1_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__I2_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__I2_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__I2_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__I2_0 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ar0;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage0__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__CIN;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_xl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_x_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_yl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_y_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ph_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ph_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__u16c_9 
        = (1U & (~ ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_ac_n)) 
                      | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0x_to_ac_n))) 
                     | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yd_to_ac_n))) 
                    | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_to_ac_n)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ix 
        = (1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_incr_to_out_n)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__u16b_4 
        = (1U & (~ ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0d_to_out_n)) 
                    | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_incr_to_out_n)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_el 
        = (1U & (~ (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_0x_to_ac_n)) 
                     | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_to_ac_n))) 
                    | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_incr_to_out_n)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_eh 
        = (1U & (~ (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yd_to_ac_n)) 
                     | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_to_ac_n))) 
                    | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__enable_yx_incr_to_out_n)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__famicom_latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__famicom_pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__xl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_xl_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__yl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_yl_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__JumpDetector__DOT__ph_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ph_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__u16c_9 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__u16c_9;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ix 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ix;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__u16b_4 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__u16b_4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_dl_n 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__u16b_4) 
                 | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__w_n))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__el 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_el;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__eh 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_eh;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_address 
        = ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_eh)
              ? 0U : (0x7fU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__Y))) 
            << 8U) | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_el)
                       ? (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__D)
                       : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__X)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__rdma_byte_transmitter__DOT__pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish__DOT__rdma_page_transmitter__DOT__rdma_frame_transmitter__DOT__famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__xl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__xl_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__yl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__yl_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__ix 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ix;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__dl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_dl_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__output_port_write 
        = (1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_dl_n)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__el 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__el;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__AddressModeDecoder__DOT__eh 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__eh;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__io_write 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__output_port_write;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__output_port_write 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__output_port_write;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__address;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request;
    CData/*0:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm;
    CData/*0:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm;
    SData/*9:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index;
    SData/*9:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index;
    SData/*9:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index;
    IData/*18:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address;
    IData/*18:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter;
    // Body
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index;
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index;
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address = 0U;
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_data = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index = 0U;
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index = 0U;
    } else {
        if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request) {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request = 0U;
        }
        if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__reg_gigatron_vsync_n) {
            if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index = 0U;
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm = 0U;
            }
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm = 1U;
        }
        if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__reg_gigatron_hsync_n) {
            if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm) {
                if ((0x20dU != (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index))) {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index)));
                }
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm = 0U;
                if ((0x19U <= (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index))) {
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter 
                        = (0x7ffffU & ((IData)(0x280U) 
                                       + vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter));
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index = 0U;
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index = 0U;
                    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address 
                        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter;
                }
            } else if ((0x19U <= (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index))) {
                __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index)));
                if ((0x2dU <= (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index))) {
                    if ((0x280U != (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index))) {
                        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index 
                            = (0x3ffU & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index)));
                        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address 
                            = (0x7ffffU & ((IData)(1U) 
                                           + vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address));
                        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_data 
                            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__reg_gigatron_eight_bit_true_color;
                        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request = 1U;
                    }
                }
            }
        } else {
            __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm = 1U;
        }
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vsync_arm;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_hsync_arm;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_line_address_counter;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_visible_line_index;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_request;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index;
    vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_framebuffer_write_data;
    vlTOPp->top__DOT__vblank = (0x1f9U < (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index));
    vlTOPp->top__DOT__hblank = (0x2adU < (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_horizontal_line_index));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__framebuffer_write_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__vblank = vlTOPp->top__DOT__vblank;
    vlTOPp->top__DOT__gigatron_shell__DOT__hblank = vlTOPp->top__DOT__hblank;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__output_framebuffer_write_address 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_address;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__output_framebuffer_write_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__framebuffer_write_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vblank 
        = vlTOPp->top__DOT__gigatron_shell__DOT__vblank;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__hblank 
        = vlTOPp->top__DOT__gigatron_shell__DOT__hblank;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vBlank 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vblank;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__hBlank 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__hblank;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reg_extended_output_port = 0U;
    } else if (vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reg_extended_output_port 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_extended_output_port 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reg_extended_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_extended_output_port 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_extended_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__led5 = (1U 
                                                   & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_extended_output_port));
    vlTOPp->top__DOT__gigatron_shell__DOT__led6 = (1U 
                                                   & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_extended_output_port) 
                                                      >> 1U));
    vlTOPp->top__DOT__gigatron_shell__DOT__led7 = (1U 
                                                   & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_extended_output_port) 
                                                      >> 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__led8 = (1U 
                                                   & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_extended_output_port) 
                                                      >> 3U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__sample 
        = (0xfU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_extended_output_port) 
                   >> 4U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__blinkenlights__DOT__ext_io_in 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_extended_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__ext_io_in 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_extended_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__extended_output_port_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__gigatron_extended_output_port;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led5 
        = vlTOPp->top__DOT__gigatron_shell__DOT__led5;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led6 
        = vlTOPp->top__DOT__gigatron_shell__DOT__led6;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led7 
        = vlTOPp->top__DOT__gigatron_shell__DOT__led7;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led8 
        = vlTOPp->top__DOT__gigatron_shell__DOT__led8;
    vlTOPp->__Vtableidx2 = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__sample;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__translated 
        = vlTOPp->__Vtable2_top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__translated
        [vlTOPp->__Vtableidx2];
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__blinkenlights__DOT__led5 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led5;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__blinkenlights__DOT__led6 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led6;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__blinkenlights__DOT__led7 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led7;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__blinkenlights__DOT__led8 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__led8;
    vlTOPp->top__DOT__AUDIO_L = (0xffffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__translated) 
                                            << 0xbU));
    vlTOPp->top__DOT__AUDIO_R = vlTOPp->top__DOT__AUDIO_L;
    vlTOPp->top__DOT__gigatron_shell__DOT__audio_dac 
        = vlTOPp->top__DOT__AUDIO_L;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio_dac 
        = vlTOPp->top__DOT__gigatron_shell__DOT__audio_dac;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio__DOT__output_audio_dac 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__audio_dac;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__8\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__famicom_latch = ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request)) 
                                       & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_latch));
    vlTOPp->top__DOT__famicom_pulse = ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request)) 
                                       & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_pulse));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__q 
        = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_cs)
            ? vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem
           [vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_address]
            : 0xffU);
    vlTOPp->top__DOT__joypad_out = vlTOPp->top__DOT__famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__famicom_latch 
        = vlTOPp->top__DOT__famicom_latch;
    vlTOPp->top__DOT__joypad_clock = (1U & (~ (IData)(vlTOPp->top__DOT__famicom_pulse)));
    vlTOPp->top__DOT__keyboard__DOT__pulse = vlTOPp->top__DOT__famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__famicom_pulse 
        = vlTOPp->top__DOT__famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_read_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__q;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__famicom_latch 
        = vlTOPp->top__DOT__gigatron_shell__DOT__famicom_latch;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__famicom_pulse 
        = vlTOPp->top__DOT__gigatron_shell__DOT__famicom_pulse;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__read_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_read_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_read_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_read_data;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__9\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift;
    // Body
    __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift;
    if (vlTOPp->reset) {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift = 0U;
    } else {
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift 
            = (0xffU & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift) 
                        << 1U));
        __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift 
            = ((0xfeU & (IData)(__Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift)) 
               | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_data));
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_output 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift 
        = __Vdly__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_shift;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__input_port_register 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__reg_output;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__input_port_register 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__input_port_register;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__input_port_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__input_port_register;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__game_controller_input 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__input_port_register;
}

VL_INLINE_OPT void Vtop::_combo__TOP__10(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__10\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__we_n 
        = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__st_n) 
           | (IData)(vlTOPp->clk_app));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__we_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__we_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_write 
        = (1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__we_n)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__InstructionDecoder__DOT__we_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__we_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_write 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_write;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__write 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_write;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_data__out__en0 
        = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_write)
            ? (((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__de_n)
                   ? 0U : 0xffU) | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__oe_n)
                                     ? 0U : 0xffU)) 
                | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ae_n)
                    ? 0U : 0xffU)) | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ie_n)
                                       ? 0U : 0xffU))
            : 0U);
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__wren 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__write;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__11(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__11\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_data 
        = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__reg_babelfish_request)
            ? (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__babelfish_data)
            : (IData)(vlTOPp->top__DOT__famicom_data));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__reg_gigatron_eight_bit_true_color 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__raw_gigatron_eight_bit_true_color));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__reg_gigatron_vsync_n 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->top__DOT__vsync_n));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__reg_gigatron_hsync_n 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->top__DOT__hsync_n));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_loader__DOT__gigatron_famicom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__famicom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron_famicom_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__famicom_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__famicom_data;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__12(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__12\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__reg_output_port) 
                 >> 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__raw_gigatron_eight_bit_true_color 
        = (((IData)(vlTOPp->top__DOT__red) << 6U) | 
           (((IData)(vlTOPp->top__DOT__green) << 3U) 
            | (IData)(vlTOPp->top__DOT__blue)));
    vlTOPp->top__DOT__vsync_n = (1U & ((IData)(vlTOPp->top__DOT__gigatron_output_port) 
                                       >> 7U));
    vlTOPp->top__DOT__hsync_n = (1U & ((IData)(vlTOPp->top__DOT__gigatron_output_port) 
                                       >> 6U));
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ld_n)))) {
        vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC 
            = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu;
    }
    vlTOPp->top__DOT__gigatron_shell__DOT__vsync_n 
        = vlTOPp->top__DOT__vsync_n;
    vlTOPp->top__DOT__VGA_VS = (1U & (~ (IData)(vlTOPp->top__DOT__vsync_n)));
    vlTOPp->top__DOT__gigatron_shell__DOT__hsync_n 
        = vlTOPp->top__DOT__hsync_n;
    vlTOPp->top__DOT__VGA_HS = (1U & (~ (IData)(vlTOPp->top__DOT__hsync_n)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ld_n 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__u16c_9) 
                 | (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__w_n))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vsync_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__vsync_n;
    vlTOPp->VGA_VS = vlTOPp->top__DOT__VGA_VS;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__hsync_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__hsync_n;
    vlTOPp->VGA_HS = vlTOPp->top__DOT__VGA_HS;
    vlTOPp->top__DOT__VGA_DE = (1U & (~ ((IData)(vlTOPp->top__DOT__VGA_HS) 
                                         | (IData)(vlTOPp->top__DOT__VGA_VS))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ld_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ld_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__ac 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 0U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 1U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 3U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 4U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 5U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 7U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ac7 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 7U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__raw_output_vsync_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vsync_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__raw_output_hsync_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__hsync_n;
    vlTOPp->VGA_DE = vlTOPp->top__DOT__VGA_DE;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ConditionDecoder__DOT__ac7 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ac7;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__13(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__13\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__discard;
    CData/*0:0*/ __Vdly__top__DOT__keyboard__DOT__ALT_R;
    // Body
    __Vdly__top__DOT__keyboard__DOT__ALT_R = vlTOPp->top__DOT__keyboard__DOT__ALT_R;
    __Vdly__top__DOT__discard = vlTOPp->top__DOT__discard;
    vlTOPp->top__DOT__keyboard__DOT__old_ps2_stb = 
        (1U & ((IData)(vlTOPp->top__DOT__ps2_key) >> 0xaU));
    if (((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->top__DOT__keyboard__DOT__old_reset)))) {
        __Vdly__top__DOT__discard = 0U;
    } else if (vlTOPp->top__DOT__keyboard__DOT__ps2_changed) {
        if ((0x12U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            vlTOPp->top__DOT__keyboard__DOT__SHIFT_L 
                = vlTOPp->top__DOT__keyboard__DOT__ps2_pressed;
        } else if ((0x59U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            vlTOPp->top__DOT__keyboard__DOT__SHIFT_R 
                = vlTOPp->top__DOT__keyboard__DOT__ps2_pressed;
        } else if ((0x14U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            vlTOPp->top__DOT__keyboard__DOT__CTRL_L 
                = vlTOPp->top__DOT__keyboard__DOT__ps2_pressed;
        } else if ((0x114U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            vlTOPp->top__DOT__keyboard__DOT__CTRL_R 
                = vlTOPp->top__DOT__keyboard__DOT__ps2_pressed;
        } else if ((0x11U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            vlTOPp->top__DOT__keyboard__DOT__ALT_L 
                = vlTOPp->top__DOT__keyboard__DOT__ps2_pressed;
        } else if ((0x111U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            __Vdly__top__DOT__keyboard__DOT__ALT_R 
                = vlTOPp->top__DOT__keyboard__DOT__ps2_pressed;
        } else if ((0x58U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            __Vdly__top__DOT__discard = ((IData)(vlTOPp->top__DOT__discard) 
                                         ^ (IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_pressed));
            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
        }
        if (vlTOPp->top__DOT__keyboard__DOT__ALT_R) {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key 
                = ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                    ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                        ? 0xffU : ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                    ? (((((((((0xeU 
                                               == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode)) 
                                              | (0x16U 
                                                 == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                             | (0x1eU 
                                                == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                            | (0x25U 
                                               == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                           | (0x26U 
                                              == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                          | (0x52U 
                                             == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                         | (0x54U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                        | (0x5bU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode)))
                                        ? ((0xeU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? (0x5cU 
                                               & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                            : ((0x16U 
                                                == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x7cU
                                                : (
                                                   (0x1eU 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                    ? 
                                                   (0x40U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                    : 
                                                   ((0x25U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 0x7eU
                                                     : 
                                                    ((0x26U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 0x23U
                                                      : 
                                                     ((0x52U 
                                                       == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 0x7bU
                                                       : 
                                                      ((0x54U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       (0x5bU 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                        : 
                                                       (0x5dU 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))))))))
                                        : ((0x5dU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0x7dU
                                            : ((0x61U 
                                                == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x7cU
                                                : 0xffU)))
                                    : (((((((((0x3dU 
                                               == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode)) 
                                              | (0x3eU 
                                                 == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                             | (0x45U 
                                                == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                            | (0x46U 
                                               == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                           | (0x4cU 
                                              == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                          | (0x4eU 
                                             == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                         | (0x52U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                        | (0x54U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode)))
                                        ? ((0x3dU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0x7bU
                                            : ((0x3eU 
                                                == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (0x5bU 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (0x45U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                    ? 0x7dU
                                                    : 
                                                   ((0x46U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 
                                                    (0x5dU 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                     : 
                                                    ((0x4cU 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 
                                                     (0x40U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                      : 
                                                     ((0x4eU 
                                                       == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 0x60U
                                                       : 
                                                      ((0x52U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 0x23U
                                                        : 
                                                       (0x5bU 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))))))))
                                        : ((0x55U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0x7eU
                                            : ((0x5bU 
                                                == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (0x5dU 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : 0xffU)))))
                    : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                        ? ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                            ? ((0x100U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                ? 0xffU : ((0x80U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0xffU
                                            : ((0x40U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                    ? 
                                                   ((0x10U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 0xffU
                                                     : 
                                                    ((8U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 0xffU
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 0xffU
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 0xffU
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0x7cU
                                                         : 0xffU)))))
                                                    : 
                                                   ((0x10U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 
                                                    ((8U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 0xffU
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 0xffU
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0x7dU
                                                         : 0xffU))
                                                       : 0xffU))
                                                     : 
                                                    ((8U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0xffU
                                                         : 
                                                        (0x5dU 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                        : 0xffU)
                                                       : 0xffU)
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0xffU
                                                         : 
                                                        (0x5eU 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 
                                                        (0x40U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                         : 0xffU))
                                                       : 0xffU))))
                                                : (
                                                   (0x20U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                    ? 
                                                   ((0x10U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 
                                                    ((8U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0xffU
                                                         : 
                                                        (0x5cU 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0x60U
                                                         : 0xffU))
                                                       : 0xffU)
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0xffU
                                                         : 0x7cU)
                                                        : 0xffU)
                                                       : 0xffU))
                                                     : 
                                                    ((8U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0xffU
                                                         : 
                                                        (0x5bU 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                        : 0xffU)
                                                       : 0xffU)
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0xffU
                                                         : 0x23U)
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 
                                                        (0x7bU 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                         : 0xffU))
                                                       : 0xffU)))
                                                    : 
                                                   ((0x10U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 
                                                    ((8U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 0xffU
                                                         : 0x7eU)
                                                        : 0xffU)
                                                       : 0xffU)
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 0xffU
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                         ? 
                                                        (0x40U 
                                                         & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                         : 0xffU))
                                                       : 0xffU))
                                                     : 0xffU)))))
                            : (((((((((0x15U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode)) 
                                      | (0x3dU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                     | (0x3eU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                    | (0x45U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                   | (0x46U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                  | (0x4eU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                 | (0x5bU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) 
                                | (0x5dU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode)))
                                ? ((0x15U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? (0x40U & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                    : ((0x3dU == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? 0x7bU : (
                                                   (0x3eU 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                    ? 
                                                   (0x5bU 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                    : 
                                                   ((0x45U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 0x7dU
                                                     : 
                                                    ((0x46U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 
                                                     (0x5dU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                      : 
                                                     ((0x4eU 
                                                       == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 
                                                      (0x5cU 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                       : 
                                                      ((0x5bU 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                        ? 0x7eU
                                                        : 0x23U)))))))
                                : ((0x61U == (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? 0x7cU : 0xffU)))
                        : 0xffU));
        } else if ((0x100U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
            if ((0x80U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            } else if ((0x40U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                    vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                                } else if ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                    vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                        = ((0xefU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                           | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                              << 4U));
                                } else {
                                    vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                    vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                                } else {
                                    vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                        = ((0xdfU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                           | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                              << 5U));
                                }
                            } else {
                                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                            } else {
                                vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                    = ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((0xf7U & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                           | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                              << 3U))
                                        : ((0xfeU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                           | (IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released)));
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                            } else {
                                vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                    = ((0xfbU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                       | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                          << 2U));
                            }
                        } else {
                            vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                = ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? (((IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL) 
                                        & (IData)(vlTOPp->top__DOT__keyboard__DOT__ALT))
                                        ? ((0xefU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                           | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                              << 4U))
                                        : ((0x7fU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                           | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                              << 7U)))
                                    : ((0xbfU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                       | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                          << 6U)));
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                            } else if ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                            } else {
                                vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                    = ((0xbfU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                       | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                          << 6U));
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                                vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                    = ((0xfdU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                       | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                          << 1U));
                            } else {
                                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))) {
                            vlTOPp->top__DOT__keyboard__DOT__joy_key 
                                = ((0x7fU & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key)) 
                                   | ((IData)(vlTOPp->top__DOT__keyboard__DOT__ps2_released) 
                                      << 7U));
                        } else {
                            vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                        }
                    } else {
                        vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
                    }
                } else {
                    vlTOPp->top__DOT__keyboard__DOT__ascii_key 
                        = ((0x10U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                            ? ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? 0xffU : ((2U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                    ? 0xffU
                                                    : 0xaU)
                                                : 0xffU))
                                : 0xffU) : ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? ((4U 
                                                 & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                 ? 0xffU
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                   ? 0xffU
                                                   : 0x2fU)
                                                  : 0xffU))
                                             : 0xffU));
                }
            } else {
                vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
            }
        } else {
            vlTOPp->top__DOT__keyboard__DOT__ascii_key 
                = ((0x80U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                    ? ((0x40U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                        ? 0xffU : ((0x20U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? 0xffU : ((0x10U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (8U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                    ? 0xffU
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                     ? 0xffU
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                       ? 0xc7U
                                                       : 0xffU)
                                                      : 0xffU))))))
                    : ((0x40U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                        ? ((0x20U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                            ? ((0x10U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                ? ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0xffU
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x39U
                                                : 0x2aU))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x2dU
                                                : 0x33U)
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x2bU
                                                : 0xcbU)))
                                    : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : 0x1bU)
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x38U
                                                : 0x36U))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x35U
                                                : 0x32U)
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x2eU
                                                : 0x30U))))
                                : ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0xffU
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : 0x37U))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x34U
                                                : 0xffU)
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x31U
                                                : 0xffU)))
                                    : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : 0x7fU)
                                            : 0xffU)
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0xffU
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 0xffU
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x7cU
                                                      : 
                                                     (0x5cU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x3eU
                                                      : 0x3cU)))
                                                : 0xffU)))))
                            : ((0x10U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                ? ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0xffU
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 0xffU
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0xffU
                                                       : 0x2aU)
                                                      : 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0x27U
                                                       : 0x23U))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0x7eU
                                                       : 0x23U)
                                                      : 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0x7cU
                                                       : 
                                                      (0x5cU 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))))
                                                : 0xffU))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0xffU
                                                     : 0x24U)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x7dU
                                                      : 
                                                     (0x5dU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x2aU
                                                      : 0x2bU)))
                                                : 0xaU)
                                            : 0xffU))
                                    : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? 0xffU
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (2U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x60U
                                                     : 0x27U)
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 
                                                     (0x5eU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                      : 0xffU)
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 0xffU
                                                      : 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0x2bU
                                                       : 0x3dU))))
                                                : (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 0xffU
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 
                                                      (0x5eU 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                       : 0x60U)
                                                      : 0xffU))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0xffU
                                                       : 
                                                      (0x5eU 
                                                       & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                      : 0xffU)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x7bU
                                                      : 
                                                     (0x5bU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x25U
                                                     : 0xffU)
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x22U
                                                      : 0x27U)
                                                     : 
                                                    ((1U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0x40U
                                                       : 0x27U)
                                                      : 0xffU))))
                                            : 0xffU)))
                                : ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 
                                                     (0x5fU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                      : 0x2dU)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL)
                                                       ? 0x7fU
                                                       : 0x3fU)
                                                      : 0x27U))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 0xffU
                                                       : 0x29U)
                                                      : 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                       ? 
                                                      ((IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL)
                                                        ? 0x7fU
                                                        : 0x3fU)
                                                       : 0xffU))
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 
                                                     (0x5fU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                      : 0x2dU))))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x50U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((0x4dU 
                                                     | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x3aU
                                                      : 0x3bU)
                                                     : 0xffU))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x4cU 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0xffU
                                                     : 0x21U)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL)
                                                       ? 0x7fU
                                                       : 0x3fU)
                                                      : 0x2fU)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 
                                                     (0x5fU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                      : 0x2dU))))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x2fU
                                                     : 0x3aU)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x3eU
                                                      : 0x2eU)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x3aU
                                                      : 0x2eU)))
                                                : 0xffU)))
                                    : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x39U
                                                     : 0xffU)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x28U
                                                      : 0x39U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x29U
                                                      : 0x39U))))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x30U
                                                     : 0xffU)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x29U
                                                      : 0x30U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x3dU
                                                      : 0x30U)))
                                                : (
                                                   (0x4fU 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x49U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (0x4bU 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x2eU
                                                     : 0x3bU)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x3cU
                                                      : 0x2cU)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x3bU
                                                      : 0x2cU)))
                                                : 0xffU))))))
                        : ((0x20U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                            ? ((0x10U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                ? ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x38U
                                                     : 
                                                    (0x5fU 
                                                     & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x2aU
                                                      : 0x38U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x28U
                                                      : 0x38U))))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x37U
                                                     : 0xffU)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x26U
                                                      : 0x37U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x2fU
                                                      : 0x37U)))
                                                : (
                                                   (0x55U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x4aU 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL)
                                                      ? 0x7fU
                                                      : 0x3fU)
                                                     : 0x2cU)
                                                    : 
                                                   ((0x4dU 
                                                     | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                            : 0xffU))
                                    : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x36U
                                                     : 0x2dU)
                                                    : 
                                                   (((0U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)) 
                                                     | (1U 
                                                        == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang)))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 
                                                     (0x5eU 
                                                      & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                      : 0x36U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x26U
                                                      : 0x36U))))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (((2U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 0x5aU
                                                      : 0x59U) 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (0x47U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x48U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (0x42U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x4eU 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : 0xffU))))
                                : ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x35U
                                                     : 0x28U)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x25U
                                                     : 0x35U)))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x52U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (0x54U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x46U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (0x56U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0x20U
                                                : 0xffU)))
                                    : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x33U
                                                     : 0x22U)
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x23U
                                                      : 0x33U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0xffU
                                                      : 0x33U))))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x34U
                                                     : 0x27U)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x24U
                                                     : 0x34U))
                                                : (
                                                   (0x45U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x44U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (0x58U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x43U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : 0xffU)))))
                            : ((0x10U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                ? ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                    ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x32U
                                                     : 0xffU)
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x40U
                                                      : 0x32U)
                                                     : 
                                                    ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                      ? 0x22U
                                                      : 0x32U))))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (((3U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 0x5aU
                                                      : 0x57U) 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (((3U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 0x51U
                                                      : 0x41U) 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                        : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (0x53U 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : (
                                                   (((3U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 0x57U
                                                      : 
                                                     ((2U 
                                                       == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                       ? 0x59U
                                                       : 0x5aU)) 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))
                                            : 0xffU))
                                    : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                        ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? 0xffU
                                                : (
                                                   (3U 
                                                    == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x31U
                                                     : 0x26U)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                     ? 0x21U
                                                     : 0x31U)))
                                            : ((1U 
                                                & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                                ? (
                                                   (((3U 
                                                      == (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                      ? 0x41U
                                                      : 0x51U) 
                                                    | (IData)(vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE)) 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))
                                                : 0xffU))
                                        : 0xffU)) : 
                               ((8U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                 ? ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                     ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                         ? ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 0xffU
                                             : ((4U 
                                                 & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                  ? 0xffU
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                   ? 0xffU
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                    ? 0x7cU
                                                    : 
                                                   (0x5cU 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK)))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                   ? 0xffU
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                    ? 0xffU
                                                    : 
                                                   (0x5eU 
                                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRLMASK))))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->top__DOT__keyboard__DOT__lang))
                                                   ? 
                                                  ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                    ? 0xffU
                                                    : 0x60U)
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT)
                                                    ? 0x7eU
                                                    : 0x60U)))))
                                         : ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 9U : 0xc4U))
                                     : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                         ? ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 0xc6U
                                             : 0xc8U)
                                         : ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 0xcaU
                                             : 0xffU)))
                                 : ((4U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                     ? ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                         ? ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 0xccU
                                             : 0xc2U)
                                         : ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 0xc1U
                                             : 0xc3U))
                                     : ((2U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                         ? ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 0xc5U
                                             : 0xffU)
                                         : ((1U & (IData)(vlTOPp->top__DOT__keyboard__DOT__keycode))
                                             ? 0xc9U
                                             : 0xffU))))))));
        }
    } else if (vlTOPp->top__DOT__keyboard__DOT__ps2_released) {
        vlTOPp->top__DOT__keyboard__DOT__ascii_key = 0xffU;
    }
    vlTOPp->top__DOT__keyboard__DOT__ALT_R = __Vdly__top__DOT__keyboard__DOT__ALT_R;
    vlTOPp->top__DOT__discard = __Vdly__top__DOT__discard;
    vlTOPp->top__DOT__keyboard__DOT__ps2_changed = 
        (1U & ((IData)(vlTOPp->top__DOT__keyboard__DOT__old_ps2_stb) 
               ^ ((IData)(vlTOPp->top__DOT__ps2_key) 
                  >> 0xaU)));
    vlTOPp->top__DOT__keyboard__DOT__ALT = ((IData)(vlTOPp->top__DOT__keyboard__DOT__ALT_L) 
                                            | (IData)(vlTOPp->top__DOT__keyboard__DOT__ALT_R));
    vlTOPp->top__DOT__keyboard__DOT__CTRL = ((IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL_L) 
                                             | (IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL_R));
    vlTOPp->top__DOT__keyboard__DOT__SHIFT = ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT_L) 
                                              | (IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT_R));
    vlTOPp->top__DOT__keyboard__DOT__caps_lock = vlTOPp->top__DOT__discard;
    vlTOPp->top__DOT__ascii_code = ((IData)(vlTOPp->top__DOT__keyboard__DOT__ascii_key) 
                                    & (IData)(vlTOPp->top__DOT__keyboard__DOT__joy_key));
    vlTOPp->top__DOT__keyboard__DOT__old_reset = vlTOPp->reset;
    vlTOPp->top__DOT__keyboard__DOT__CTRLMASK = ((IData)(vlTOPp->top__DOT__keyboard__DOT__CTRL)
                                                  ? 0x1fU
                                                  : 0xffU);
    vlTOPp->top__DOT__keyboard__DOT__CAPSTOGGLE = (
                                                   ((IData)(vlTOPp->top__DOT__keyboard__DOT__SHIFT) 
                                                    ^ (IData)(vlTOPp->top__DOT__discard))
                                                    ? 0U
                                                    : 0x20U);
    vlTOPp->top__DOT__ascii_bitmap = ((0x80U & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                << 7U)) 
                                      | ((0x40U & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                   << 5U)) 
                                         | ((0x20U 
                                             & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                << 3U)) 
                                            | ((0x10U 
                                                & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                   << 1U)) 
                                               | ((8U 
                                                   & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                      >> 1U)) 
                                                  | ((4U 
                                                      & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                         >> 3U)) 
                                                     | ((2U 
                                                         & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                            >> 5U)) 
                                                        | (1U 
                                                           & ((IData)(vlTOPp->top__DOT__ascii_code) 
                                                              >> 7U)))))))));
    vlTOPp->top__DOT__keyboard__DOT__ascii_code = vlTOPp->top__DOT__ascii_code;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__14(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__14\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus 
        = ((((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__de_n)
                ? 0U : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__D)) 
              & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__de_n)
                  ? 0U : 0xffU)) | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__oe_n)
                                      ? 0U : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_read_data)) 
                                    & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__oe_n)
                                        ? 0U : 0xffU))) 
            | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ae_n)
                 ? 0U : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC)) 
               & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ae_n)
                   ? 0U : 0xffU))) | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ie_n)
                                        ? 0U : (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__game_controller_input)) 
                                      & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ie_n)
                                          ? 0U : 0xffU)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__bus 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 0U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 1U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__S1 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 3U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 4U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 5U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__S0 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 7U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit0__Y2 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus))) 
                  | ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                     & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus))) 
                 & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit1__Y2 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                         >> 1U))) | ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                                     & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                        >> 1U))) & 
                 ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                  >> 1U)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit2__Y2 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                         >> 2U))) | ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                                     & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                        >> 2U))) & 
                 ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                  >> 2U)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit3__Y2 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                         >> 3U))) | ((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                                     & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                        >> 3U))) & 
                 ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                  >> 3U)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit5__Y1 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                      >> 5U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                    >> 5U))) | (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                                                 & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                                    >> 5U)) 
                                                & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                                   >> 5U))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit7__Y1 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                      >> 7U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                    >> 7U))) | (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                                                 & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                                    >> 7U)) 
                                                & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                                   >> 7U))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit4__Y1 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                      >> 4U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                    >> 4U))) | (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                                                 & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                                    >> 4U)) 
                                                & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                                   >> 4U))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit6__Y1 
        = (1U & ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                   & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                      >> 6U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                    >> 6U))) | (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_al)) 
                                                 & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                                    >> 6U)) 
                                                & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                                   >> 6U))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit0__Y1 
        = ((((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus)) 
               & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC))) 
              & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus)) 
                 & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC)) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
            | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC))) 
               & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
           | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
               & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC)) 
              & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit1__Y1 
        = ((((((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                   >> 1U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                 >> 1U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                     >> 1U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                >> 1U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
            | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 1U) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                              >> 1U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
           | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC)) 
               >> 1U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit2__Y1 
        = ((((((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                   >> 2U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                 >> 2U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                     >> 2U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                >> 2U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
            | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 2U) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                              >> 2U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
           | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC)) 
               >> 2U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit3__Y1 
        = ((((((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                   >> 3U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                 >> 3U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                     >> 3U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                >> 3U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
            | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                 >> 3U) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                              >> 3U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
           | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC)) 
               >> 3U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit4__Y2 
        = ((((((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                   >> 4U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                 >> 4U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                     >> 4U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                >> 4U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
            | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 4U) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                              >> 4U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
           | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus)) 
               >> 4U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit6__Y2 
        = ((((((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                   >> 6U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                 >> 6U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                     >> 6U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                >> 6U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
            | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 6U) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                              >> 6U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
           | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus)) 
               >> 6U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit5__Y2 
        = ((((((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                   >> 5U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                 >> 5U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                     >> 5U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                >> 5U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
            | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 5U) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                              >> 5U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
           | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus)) 
               >> 5U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit7__Y2 
        = ((((((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                   >> 7U)) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                 >> 7U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar0)) 
             | (((~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                     >> 7U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                                >> 7U)) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar2))) 
            | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                 >> 7U) & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus) 
                              >> 7U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar1))) 
           | ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus)) 
               >> 7U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ar3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit0__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b 
        = ((0xfeU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b)) 
           | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit0__Y2));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit1__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b 
        = ((0xfdU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit1__Y2) 
              << 1U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit2__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b 
        = ((0xfbU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit2__Y2) 
              << 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit3__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b 
        = ((0xf7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit3__Y2) 
              << 3U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit5__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b 
        = ((0xdfU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit5__Y1) 
              << 5U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit7__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a 
        = ((0x7fU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit7__Y1) 
              << 7U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit4__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit6__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit0__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit0__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a 
        = ((0xfeU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a)) 
           | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit0__Y1));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit1__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit1__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a 
        = ((0xfdU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit1__Y1) 
              << 1U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit2__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit2__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a 
        = ((0xfbU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit2__Y1) 
              << 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit3__DOT__Y1 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit3__Y1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a 
        = ((0xf7U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit3__Y1) 
              << 3U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit4__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit4__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b 
        = ((0xefU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit4__Y2) 
              << 4U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit6__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit6__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a 
        = ((0xbfU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a)) 
           | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit6__Y2) 
              << 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit5__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit5__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a 
        = ((0xcfU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a)) 
           | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit5__Y2) 
               << 5U) | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit4__Y1) 
                         << 4U)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_decoder_bit7__DOT__Y2 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit7__Y2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b 
        = ((0x3fU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b)) 
           | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit7__Y2) 
               << 7U) | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__alu_decoder_bit6__Y1) 
                         << 6U)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_a;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu_operand_b;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage0__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 0U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage1__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 1U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage2__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage3__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 3U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage4__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 4U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage5__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 5U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage6__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage7__DOT__A 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                 >> 7U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage0__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 0U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage1__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 1U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage2__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 2U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage3__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 3U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage4__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 4U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage5__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 5U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage6__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 6U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage7__DOT__B 
        = (1U & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                 >> 7U));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage0____pinNumber4 
        = (1U & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                  ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                 ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__CIN)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry1 
        = (1U & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                  & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__CIN))) 
                 | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                    & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__CIN))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage0__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage0____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage0__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage1__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry1;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage1____pinNumber4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                  >> 1U) ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry1)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry2 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   >> 1U) & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                              >> 1U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry1))) 
                 | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     >> 1U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry1))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage1__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage1____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage1__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage2__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry2;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage2____pinNumber4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                  >> 2U) ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry2)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry3 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   >> 2U) & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                              >> 2U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry2))) 
                 | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     >> 2U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry2))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage2__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage2____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage2__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage3__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry3;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage3____pinNumber4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                  >> 3U) ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry3)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   >> 3U) & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                              >> 3U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry3))) 
                 | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     >> 3U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry3))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage3__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage3____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__S 
        = ((0xf0U & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__S)) 
           | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage3____pinNumber4) 
               << 3U) | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage2____pinNumber4) 
                          << 2U) | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage1____pinNumber4) 
                                     << 1U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage0____pinNumber4)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage3__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage4__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage4____pinNumber4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                  >> 4U) ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry4)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry5 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   >> 4U) & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                              >> 4U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry4))) 
                 | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     >> 4U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry4))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage4__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage4____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage4__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry5;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage5__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry5;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage5____pinNumber4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                  >> 5U) ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry5)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry6 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   >> 5U) & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                              >> 5U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry5))) 
                 | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     >> 5U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry5))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage5__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage5____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage5__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry6;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage6__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry6;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage6____pinNumber4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                  >> 6U) ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry6)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry7 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   >> 6U) & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                              >> 6U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry6))) 
                 | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     >> 6U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry6))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage6__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage6____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage6__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry7;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage7__DOT__CIN 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry7;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage7____pinNumber4 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B)) 
                  >> 7U) ^ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry7)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu_co 
        = (1U & ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__A) 
                   >> 7U) & (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                              >> 7U) | (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry7))) 
                 | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__B) 
                     >> 7U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__carry7))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage7__DOT__S 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage7____pinNumber4;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__S 
        = ((0xfU & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__S)) 
           | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage7____pinNumber4) 
               << 7U) | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage6____pinNumber4) 
                          << 6U) | (((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage5____pinNumber4) 
                                     << 5U) | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT____Vcellout__stage4____pinNumber4) 
                                               << 4U)))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__co 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu_co;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__co 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu_co;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ConditionDecoder__DOT__inv_c_in 
        = (1U & ((((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n)) 
                     & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu_co))) 
                    & (~ ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                          >> 7U))) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__condition)) 
                  | ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n)) 
                       & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu_co))) 
                      & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                         >> 7U)) & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__condition) 
                                    >> 1U))) | ((((~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__j_n)) 
                                                  & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu_co)) 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__AC) 
                                                     >> 7U))) 
                                                & ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__condition) 
                                                   >> 2U))));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__S;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ConditionDecoder__DOT__co 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__co;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__stage7__DOT__COUT 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__co;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__inv_c_out_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ConditionDecoder__DOT__inv_c_in)));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ALU__DOT__alu 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__alu;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__ConditionDecoder__DOT__inv_c_out_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__inv_c_out_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__JumpDetector__DOT__inv_c_out_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__inv_c_out_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_pl_n 
        = ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_ph_n) 
           & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__inv_c_out_n));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__pl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__cu_pl_n;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__JumpDetector__DOT__pl_n 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ControlUnit__DOT__pl_n;
}

VL_INLINE_OPT void Vtop::_combo__TOP__15(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__15\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_data 
        = ((((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_write)
              ? (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__bus)
              : 0U) & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_data__out__en0)) 
           & (IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_data__out__en0));
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__ram_data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram_data;
    vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__data 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__data;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
    if (((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_app) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_app)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_vid) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_vid)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock))))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk_app) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_app))) 
         | ((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys))))) {
        vlTOPp->_multiclk__TOP__8(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__serial_clock) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__serial_clock))))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    vlTOPp->_combo__TOP__10(vlSymsp);
    if (((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys)))) {
        vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_app) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_app)))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__famicom_pulse) & 
         (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__famicom_pulse)))) {
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if ((((((IData)(vlTOPp->clk_app) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_app))) 
           | ((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys)))) 
          | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset)))) 
         | ((IData)(vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__serial_clock) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__serial_clock))))) {
        vlTOPp->_multiclk__TOP__14(vlSymsp);
    }
    vlTOPp->_combo__TOP__15(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk_sys = vlTOPp->clk_sys;
    vlTOPp->__Vclklast__TOP__clk_app = vlTOPp->clk_app;
    vlTOPp->__Vclklast__TOP__clk_vid = vlTOPp->clk_vid;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock 
        = vlTOPp->__VinpClk__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock;
    vlTOPp->__Vclklast__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__serial_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__serial_controller__DOT__serial_clock;
    vlTOPp->__Vclklast__TOP__top__DOT__famicom_pulse 
        = vlTOPp->top__DOT__famicom_pulse;
    vlTOPp->__VinpClk__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock ^ vlTOPp->__Vchglast__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock ^ vlTOPp->__Vchglast__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock))) VL_DBG_MSGF("        CHANGE: ../rtl/gigatron_onefile.sv:1625: top.gigatron_shell.gigatron.cpu.aux_io_clock\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock 
        = vlTOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__aux_io_clock;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_sys & 0xfeU))) {
        Verilated::overWidthError("clk_sys");}
    if (VL_UNLIKELY((clk_vid & 0xfeU))) {
        Verilated::overWidthError("clk_vid");}
    if (VL_UNLIKELY((clk_app & 0xfeU))) {
        Verilated::overWidthError("clk_app");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((ioctl_upload & 0xfeU))) {
        Verilated::overWidthError("ioctl_upload");}
    if (VL_UNLIKELY((ioctl_download & 0xfeU))) {
        Verilated::overWidthError("ioctl_download");}
    if (VL_UNLIKELY((ioctl_wr & 0xfeU))) {
        Verilated::overWidthError("ioctl_wr");}
    if (VL_UNLIKELY((ioctl_addr & 0xfe000000U))) {
        Verilated::overWidthError("ioctl_addr");}
}
#endif  // VL_DEBUG
