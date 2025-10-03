// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmini_rv32i.h for the primary calling header

#include "Vmini_rv32i__pch.h"
#include "Vmini_rv32i___024root.h"

VL_ATTR_COLD void Vmini_rv32i___024root___eval_static(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_static\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vmini_rv32i___024root___eval_initial__TOP(Vmini_rv32i___024root* vlSelf);

VL_ATTR_COLD void Vmini_rv32i___024root___eval_initial(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_initial\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmini_rv32i___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vmini_rv32i___024root___eval_initial__TOP(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_initial__TOP\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x70726f67U;
    __Vtemp_1[2U] = 0x6172652fU;
    __Vtemp_1[3U] = 0x69726d77U;
    __Vtemp_1[4U] = 0x66U;
    VL_READMEM_N(true, 32, 256, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_1)
                 ,  &(vlSelfRef.mini_rv32i__DOT__imem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vmini_rv32i___024root___eval_final(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_final\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmini_rv32i___024root___dump_triggers__stl(Vmini_rv32i___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmini_rv32i___024root___eval_phase__stl(Vmini_rv32i___024root* vlSelf);

VL_ATTR_COLD void Vmini_rv32i___024root___eval_settle(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_settle\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vmini_rv32i___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/mini_rv32i.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vmini_rv32i___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmini_rv32i___024root___dump_triggers__stl(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___dump_triggers__stl\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmini_rv32i___024root___stl_sequent__TOP__0(Vmini_rv32i___024root* vlSelf);
VL_ATTR_COLD void Vmini_rv32i___024root____Vm_traceActivitySetAll(Vmini_rv32i___024root* vlSelf);

VL_ATTR_COLD void Vmini_rv32i___024root___eval_stl(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_stl\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vmini_rv32i___024root___stl_sequent__TOP__0(vlSelf);
        Vmini_rv32i___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vmini_rv32i___024root___stl_sequent__TOP__0(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___stl_sequent__TOP__0\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mini_rv32i__DOT__instr = vlSelfRef.mini_rv32i__DOT__imem
        [(0xffU & (vlSelfRef.mini_rv32i__DOT__pc >> 2U))];
    vlSelfRef.mini_rv32i__DOT__addr_s = (vlSelfRef.mini_rv32i__DOT__x
                                         [(0x1fU & 
                                           (vlSelfRef.mini_rv32i__DOT__instr 
                                            >> 0xfU))] 
                                         + (((- (IData)(
                                                        (vlSelfRef.mini_rv32i__DOT__instr 
                                                         >> 0x1fU))) 
                                             << 0xcU) 
                                            | ((0xfe0U 
                                                & (vlSelfRef.mini_rv32i__DOT__instr 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelfRef.mini_rv32i__DOT__instr 
                                                     >> 7U)))));
    vlSelfRef.mini_rv32i__DOT__imm_i = (((- (IData)(
                                                    (vlSelfRef.mini_rv32i__DOT__instr 
                                                     >> 0x1fU))) 
                                         << 0xcU) | 
                                        (vlSelfRef.mini_rv32i__DOT__instr 
                                         >> 0x14U));
    vlSelfRef.mini_rv32i__DOT__addr_i = (vlSelfRef.mini_rv32i__DOT__x
                                         [(0x1fU & 
                                           (vlSelfRef.mini_rv32i__DOT__instr 
                                            >> 0xfU))] 
                                         + vlSelfRef.mini_rv32i__DOT__imm_i);
}

VL_ATTR_COLD void Vmini_rv32i___024root___eval_triggers__stl(Vmini_rv32i___024root* vlSelf);

VL_ATTR_COLD bool Vmini_rv32i___024root___eval_phase__stl(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_phase__stl\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmini_rv32i___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vmini_rv32i___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmini_rv32i___024root___dump_triggers__act(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___dump_triggers__act\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmini_rv32i___024root___dump_triggers__nba(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___dump_triggers__nba\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmini_rv32i___024root____Vm_traceActivitySetAll(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root____Vm_traceActivitySetAll\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vmini_rv32i___024root___ctor_var_reset(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___ctor_var_reset\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->io_in_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6960165711390335857ull);
    vlSelf->io_in_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7028534506139813993ull);
    vlSelf->io_op = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2536292131817234354ull);
    vlSelf->io_out_res = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3215169811637132235ull);
    vlSelf->io_out_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1069148654264965181ull);
    vlSelf->x3_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 402779371771456202ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->mini_rv32i__DOT__x[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7064814613825951266ull);
    }
    vlSelf->mini_rv32i__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17550605169690026191ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->mini_rv32i__DOT__imem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5459497975094381845ull);
    }
    vlSelf->mini_rv32i__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3520505309365803978ull);
    vlSelf->mini_rv32i__DOT__imm_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14957259425003082478ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->mini_rv32i__DOT__dmem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6366114000171370330ull);
    }
    vlSelf->mini_rv32i__DOT__addr_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11139738669412417180ull);
    vlSelf->mini_rv32i__DOT__addr_s = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6081462666365115989ull);
    vlSelf->mini_rv32i__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1162747992160039723ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
