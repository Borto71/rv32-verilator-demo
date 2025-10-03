// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmini_rv32i.h for the primary calling header

#ifndef VERILATED_VMINI_RV32I___024ROOT_H_
#define VERILATED_VMINI_RV32I___024ROOT_H_  // guard

#include "verilated.h"


class Vmini_rv32i__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmini_rv32i___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(io_op,1,0);
    VL_OUT8(io_out_valid,0,0);
    VL_OUT8(done,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(io_in_a,31,0);
    VL_IN(io_in_b,31,0);
    VL_OUT(io_out_res,31,0);
    VL_OUT(x3_out,31,0);
    IData/*31:0*/ mini_rv32i__DOT__pc;
    IData/*31:0*/ mini_rv32i__DOT__instr;
    IData/*31:0*/ mini_rv32i__DOT__imm_i;
    IData/*31:0*/ mini_rv32i__DOT__addr_i;
    IData/*31:0*/ mini_rv32i__DOT__addr_s;
    IData/*31:0*/ mini_rv32i__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> mini_rv32i__DOT__x;
    VlUnpacked<IData/*31:0*/, 256> mini_rv32i__DOT__imem;
    VlUnpacked<IData/*31:0*/, 256> mini_rv32i__DOT__dmem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmini_rv32i__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmini_rv32i___024root(Vmini_rv32i__Syms* symsp, const char* v__name);
    ~Vmini_rv32i___024root();
    VL_UNCOPYABLE(Vmini_rv32i___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
