// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vtop.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vtop__Syms : public VerilatedSyms {
  public:

    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;

    // SUBCELL STATE
    Vtop*                          TOPp;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_top;
    VerilatedScope __Vscope_top__gigatron_shell__gigatron__ram__gigatron_ram_inst;
    VerilatedScope __Vscope_top__gigatron_shell__gigatron__vga;

    // CREATORS
    Vtop__Syms(VerilatedContext* contextp, Vtop* topp, const char* namep);
    ~Vtop__Syms();

    // METHODS
    inline const char* name() { return __Vm_namep; }
    void __Vserialize(VerilatedSerialize& os);
    void __Vdeserialize(VerilatedDeserialize& os);

} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
