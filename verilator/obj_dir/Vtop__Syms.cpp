// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"


void Vtop__Syms::__Vserialize(VerilatedSerialize& os) {
    // LOCAL STATE
    os<<__Vm_activity;
    os<<__Vm_didInit;
    // SUBCELL STATE
}
void Vtop__Syms::__Vdeserialize(VerilatedDeserialize& os) {
    // LOCAL STATE
    os>>__Vm_activity;
    os>>__Vm_didInit;
    // SUBCELL STATE
}


// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, Vtop* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_top.configure(this, name(), "top", "top", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__gigatron_shell__gigatron__ram__gigatron_ram_inst.configure(this, name(), "top.gigatron_shell.gigatron.ram.gigatron_ram_inst", "gigatron_ram_inst", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__gigatron_shell__gigatron__vga.configure(this, name(), "top.gigatron_shell.gigatron.vga", "vga", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_TOP.varInsert(__Vfinal,"VGA_B", &(TOPp->VGA_B), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"VGA_DE", &(TOPp->VGA_DE), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"VGA_G", &(TOPp->VGA_G), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"VGA_HS", &(TOPp->VGA_HS), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"VGA_R", &(TOPp->VGA_R), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"VGA_VS", &(TOPp->VGA_VS), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk_app", &(TOPp->clk_app), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk_sys", &(TOPp->clk_sys), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk_vid", &(TOPp->clk_vid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOPp->reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_top.varInsert(__Vfinal,"VGA_B", &(TOPp->top__DOT__VGA_B), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_top.varInsert(__Vfinal,"VGA_DE", &(TOPp->top__DOT__VGA_DE), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top.varInsert(__Vfinal,"VGA_G", &(TOPp->top__DOT__VGA_G), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_top.varInsert(__Vfinal,"VGA_HS", &(TOPp->top__DOT__VGA_HS), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top.varInsert(__Vfinal,"VGA_R", &(TOPp->top__DOT__VGA_R), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_top.varInsert(__Vfinal,"VGA_VS", &(TOPp->top__DOT__VGA_VS), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top.varInsert(__Vfinal,"clk_app", &(TOPp->top__DOT__clk_app), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top.varInsert(__Vfinal,"clk_sys", &(TOPp->top__DOT__clk_sys), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top.varInsert(__Vfinal,"clk_vid", &(TOPp->top__DOT__clk_vid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top.varInsert(__Vfinal,"joystick", &(TOPp->top__DOT__joystick), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_top.varInsert(__Vfinal,"ps2_key", &(TOPp->top__DOT__ps2_key), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,10,0);
        __Vscope_top.varInsert(__Vfinal,"reset", &(TOPp->top__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top__gigatron_shell__gigatron__ram__gigatron_ram_inst.varInsert(__Vfinal,"address", &(TOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__address), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,14,0);
        __Vscope_top__gigatron_shell__gigatron__ram__gigatron_ram_inst.varInsert(__Vfinal,"data", &(TOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__data), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_top__gigatron_shell__gigatron__ram__gigatron_ram_inst.varInsert(__Vfinal,"mem", &(TOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__mem), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,2 ,7,0 ,32767,0);
        __Vscope_top__gigatron_shell__gigatron__ram__gigatron_ram_inst.varInsert(__Vfinal,"q", &(TOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__q), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_top__gigatron_shell__gigatron__ram__gigatron_ram_inst.varInsert(__Vfinal,"wren", &(TOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__wren), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_top__gigatron_shell__gigatron__vga.varInsert(__Vfinal,"vga_vertical_line_index", &(TOPp->top__DOT__gigatron_shell__DOT__gigatron__DOT__vga__DOT__vga_vertical_line_index), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,9,0);
    }
}
