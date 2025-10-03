// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmini_rv32i.h for the primary calling header

#include "Vmini_rv32i__pch.h"
#include "Vmini_rv32i__Syms.h"
#include "Vmini_rv32i___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmini_rv32i___024root___dump_triggers__stl(Vmini_rv32i___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmini_rv32i___024root___eval_triggers__stl(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_triggers__stl\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmini_rv32i___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
