// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmini_rv32i.h for the primary calling header

#include "Vmini_rv32i__pch.h"
#include "Vmini_rv32i___024root.h"

void Vmini_rv32i___024root___eval_act(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_act\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vmini_rv32i___024root___nba_sequent__TOP__0(Vmini_rv32i___024root* vlSelf);

void Vmini_rv32i___024root___eval_nba(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_nba\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vmini_rv32i___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vmini_rv32i___024root___nba_sequent__TOP__0(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___nba_sequent__TOP__0\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vtask_mini_rv32i__DOT__mmio_write__0__addr;
    __Vtask_mini_rv32i__DOT__mmio_write__0__addr = 0;
    IData/*31:0*/ __Vtask_mini_rv32i__DOT__mmio_write__0__wdata;
    __Vtask_mini_rv32i__DOT__mmio_write__0__wdata = 0;
    IData/*31:0*/ __Vfunc_mini_rv32i__DOT__mmio_read__1__Vfuncout;
    __Vfunc_mini_rv32i__DOT__mmio_read__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_mini_rv32i__DOT__mmio_read__1__addr;
    __Vfunc_mini_rv32i__DOT__mmio_read__1__addr = 0;
    IData/*31:0*/ __Vdly__mini_rv32i__DOT__pc;
    __Vdly__mini_rv32i__DOT__pc = 0;
    CData/*0:0*/ __Vdly__done;
    __Vdly__done = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v0;
    __VdlySet__mini_rv32i__DOT__x__v0 = 0;
    IData/*31:0*/ __VdlyVal__mini_rv32i__DOT__x__v32;
    __VdlyVal__mini_rv32i__DOT__x__v32 = 0;
    CData/*4:0*/ __VdlyDim0__mini_rv32i__DOT__x__v32;
    __VdlyDim0__mini_rv32i__DOT__x__v32 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v32;
    __VdlySet__mini_rv32i__DOT__x__v32 = 0;
    IData/*31:0*/ __VdlyVal__mini_rv32i__DOT__x__v33;
    __VdlyVal__mini_rv32i__DOT__x__v33 = 0;
    CData/*4:0*/ __VdlyDim0__mini_rv32i__DOT__x__v33;
    __VdlyDim0__mini_rv32i__DOT__x__v33 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v33;
    __VdlySet__mini_rv32i__DOT__x__v33 = 0;
    IData/*31:0*/ __VdlyVal__mini_rv32i__DOT__x__v34;
    __VdlyVal__mini_rv32i__DOT__x__v34 = 0;
    CData/*4:0*/ __VdlyDim0__mini_rv32i__DOT__x__v34;
    __VdlyDim0__mini_rv32i__DOT__x__v34 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v34;
    __VdlySet__mini_rv32i__DOT__x__v34 = 0;
    IData/*31:0*/ __VdlyVal__mini_rv32i__DOT__dmem__v0;
    __VdlyVal__mini_rv32i__DOT__dmem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__mini_rv32i__DOT__dmem__v0;
    __VdlyDim0__mini_rv32i__DOT__dmem__v0 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__dmem__v0;
    __VdlySet__mini_rv32i__DOT__dmem__v0 = 0;
    IData/*31:0*/ __VdlyVal__mini_rv32i__DOT__x__v35;
    __VdlyVal__mini_rv32i__DOT__x__v35 = 0;
    CData/*4:0*/ __VdlyDim0__mini_rv32i__DOT__x__v35;
    __VdlyDim0__mini_rv32i__DOT__x__v35 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v35;
    __VdlySet__mini_rv32i__DOT__x__v35 = 0;
    IData/*31:0*/ __VdlyVal__mini_rv32i__DOT__x__v36;
    __VdlyVal__mini_rv32i__DOT__x__v36 = 0;
    CData/*4:0*/ __VdlyDim0__mini_rv32i__DOT__x__v36;
    __VdlyDim0__mini_rv32i__DOT__x__v36 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v36;
    __VdlySet__mini_rv32i__DOT__x__v36 = 0;
    IData/*31:0*/ __VdlyVal__mini_rv32i__DOT__x__v37;
    __VdlyVal__mini_rv32i__DOT__x__v37 = 0;
    CData/*4:0*/ __VdlyDim0__mini_rv32i__DOT__x__v37;
    __VdlyDim0__mini_rv32i__DOT__x__v37 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v37;
    __VdlySet__mini_rv32i__DOT__x__v37 = 0;
    CData/*0:0*/ __VdlySet__mini_rv32i__DOT__x__v38;
    __VdlySet__mini_rv32i__DOT__x__v38 = 0;
    // Body
    __Vdly__done = vlSelfRef.done;
    __VdlySet__mini_rv32i__DOT__dmem__v0 = 0U;
    __Vdly__mini_rv32i__DOT__pc = vlSelfRef.mini_rv32i__DOT__pc;
    __VdlySet__mini_rv32i__DOT__x__v0 = 0U;
    __VdlySet__mini_rv32i__DOT__x__v32 = 0U;
    __VdlySet__mini_rv32i__DOT__x__v33 = 0U;
    __VdlySet__mini_rv32i__DOT__x__v34 = 0U;
    __VdlySet__mini_rv32i__DOT__x__v35 = 0U;
    __VdlySet__mini_rv32i__DOT__x__v36 = 0U;
    __VdlySet__mini_rv32i__DOT__x__v37 = 0U;
    __VdlySet__mini_rv32i__DOT__x__v38 = 0U;
    if (vlSelfRef.rst) {
        vlSelfRef.mini_rv32i__DOT__i = 0x20U;
        __Vdly__mini_rv32i__DOT__pc = 0U;
        __Vdly__done = 0U;
        vlSelfRef.x3_out = 0U;
        vlSelfRef.io_out_res = 0U;
        vlSelfRef.io_out_valid = 0U;
        __VdlySet__mini_rv32i__DOT__x__v0 = 1U;
    } else if ((1U & (~ (IData)(vlSelfRef.done)))) {
        if ((0x40U & vlSelfRef.mini_rv32i__DOT__instr)) {
            if ((0x20U & vlSelfRef.mini_rv32i__DOT__instr)) {
                if ((0x10U & vlSelfRef.mini_rv32i__DOT__instr)) {
                    if ((8U & vlSelfRef.mini_rv32i__DOT__instr)) {
                        __Vdly__mini_rv32i__DOT__pc 
                            = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                    } else if ((4U & vlSelfRef.mini_rv32i__DOT__instr)) {
                        __Vdly__mini_rv32i__DOT__pc 
                            = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                    } else if ((2U & vlSelfRef.mini_rv32i__DOT__instr)) {
                        if ((1U & vlSelfRef.mini_rv32i__DOT__instr)) {
                            __Vdly__mini_rv32i__DOT__pc 
                                = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                            if ((1U == (vlSelfRef.mini_rv32i__DOT__instr 
                                        >> 0x14U))) {
                                __Vdly__done = 1U;
                                vlSelfRef.x3_out = 
                                    vlSelfRef.mini_rv32i__DOT__x
                                    [3U];
                            }
                        } else {
                            __Vdly__mini_rv32i__DOT__pc 
                                = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                        }
                    } else {
                        __Vdly__mini_rv32i__DOT__pc 
                            = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                    }
                } else {
                    __Vdly__mini_rv32i__DOT__pc = (
                                                   (8U 
                                                    & vlSelfRef.mini_rv32i__DOT__instr)
                                                    ? 
                                                   ((IData)(4U) 
                                                    + vlSelfRef.mini_rv32i__DOT__pc)
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.mini_rv32i__DOT__instr)
                                                     ? 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.mini_rv32i__DOT__pc)
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.mini_rv32i__DOT__instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.mini_rv32i__DOT__instr)
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (7U 
                                                         & (vlSelfRef.mini_rv32i__DOT__instr 
                                                            >> 0xcU)))
                                                        ? 
                                                       ((vlSelfRef.mini_rv32i__DOT__x
                                                         [
                                                         (0x1fU 
                                                          & (vlSelfRef.mini_rv32i__DOT__instr 
                                                             >> 0xfU))] 
                                                         == 
                                                         vlSelfRef.mini_rv32i__DOT__x
                                                         [
                                                         (0x1fU 
                                                          & (vlSelfRef.mini_rv32i__DOT__instr 
                                                             >> 0x14U))])
                                                         ? 
                                                        (vlSelfRef.mini_rv32i__DOT__pc 
                                                         + 
                                                         (((- (IData)(
                                                                      (vlSelfRef.mini_rv32i__DOT__instr 
                                                                       >> 0x1fU))) 
                                                           << 0xdU) 
                                                          | ((((2U 
                                                                & (vlSelfRef.mini_rv32i__DOT__instr 
                                                                   >> 0x1eU)) 
                                                               | (1U 
                                                                  & (vlSelfRef.mini_rv32i__DOT__instr 
                                                                     >> 7U))) 
                                                              << 0xbU) 
                                                             | ((0x7e0U 
                                                                 & (vlSelfRef.mini_rv32i__DOT__instr 
                                                                    >> 0x14U)) 
                                                                | (0x1eU 
                                                                   & (vlSelfRef.mini_rv32i__DOT__instr 
                                                                      >> 7U))))))
                                                         : 
                                                        ((IData)(4U) 
                                                         + vlSelfRef.mini_rv32i__DOT__pc))
                                                        : 
                                                       ((IData)(4U) 
                                                        + vlSelfRef.mini_rv32i__DOT__pc))
                                                       : 
                                                      ((IData)(4U) 
                                                       + vlSelfRef.mini_rv32i__DOT__pc))
                                                      : 
                                                     ((IData)(4U) 
                                                      + vlSelfRef.mini_rv32i__DOT__pc))));
                }
            } else {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            }
        } else if ((0x20U & vlSelfRef.mini_rv32i__DOT__instr)) {
            if ((0x10U & vlSelfRef.mini_rv32i__DOT__instr)) {
                if ((8U & vlSelfRef.mini_rv32i__DOT__instr)) {
                    __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                                   + vlSelfRef.mini_rv32i__DOT__pc);
                } else if ((4U & vlSelfRef.mini_rv32i__DOT__instr)) {
                    if ((2U & vlSelfRef.mini_rv32i__DOT__instr)) {
                        if ((1U & vlSelfRef.mini_rv32i__DOT__instr)) {
                            __Vdly__mini_rv32i__DOT__pc 
                                = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                            if ((0U != (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                 >> 7U)))) {
                                __VdlyVal__mini_rv32i__DOT__x__v32 
                                    = (0xfffff000U 
                                       & vlSelfRef.mini_rv32i__DOT__instr);
                                __VdlyDim0__mini_rv32i__DOT__x__v32 
                                    = (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                >> 7U));
                                __VdlySet__mini_rv32i__DOT__x__v32 = 1U;
                            }
                        } else {
                            __Vdly__mini_rv32i__DOT__pc 
                                = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                        }
                    } else {
                        __Vdly__mini_rv32i__DOT__pc 
                            = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                    }
                } else if ((2U & vlSelfRef.mini_rv32i__DOT__instr)) {
                    if ((1U & vlSelfRef.mini_rv32i__DOT__instr)) {
                        if ((IData)((0U == (0xfe007000U 
                                            & vlSelfRef.mini_rv32i__DOT__instr)))) {
                            if ((0U != (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                 >> 7U)))) {
                                __VdlyVal__mini_rv32i__DOT__x__v33 
                                    = (vlSelfRef.mini_rv32i__DOT__x
                                       [(0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                  >> 0xfU))] 
                                       + vlSelfRef.mini_rv32i__DOT__x
                                       [(0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                  >> 0x14U))]);
                                __VdlyDim0__mini_rv32i__DOT__x__v33 
                                    = (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                >> 7U));
                                __VdlySet__mini_rv32i__DOT__x__v33 = 1U;
                            }
                        } else if ((IData)((0x40000000U 
                                            == (0xfe007000U 
                                                & vlSelfRef.mini_rv32i__DOT__instr)))) {
                            if ((0U != (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                 >> 7U)))) {
                                __VdlyVal__mini_rv32i__DOT__x__v34 
                                    = (vlSelfRef.mini_rv32i__DOT__x
                                       [(0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                  >> 0xfU))] 
                                       - vlSelfRef.mini_rv32i__DOT__x
                                       [(0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                  >> 0x14U))]);
                                __VdlyDim0__mini_rv32i__DOT__x__v34 
                                    = (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                >> 7U));
                                __VdlySet__mini_rv32i__DOT__x__v34 = 1U;
                            }
                        }
                        __Vdly__mini_rv32i__DOT__pc 
                            = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                    } else {
                        __Vdly__mini_rv32i__DOT__pc 
                            = ((IData)(4U) + vlSelfRef.mini_rv32i__DOT__pc);
                    }
                } else {
                    __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                                   + vlSelfRef.mini_rv32i__DOT__pc);
                }
            } else if ((8U & vlSelfRef.mini_rv32i__DOT__instr)) {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            } else if ((4U & vlSelfRef.mini_rv32i__DOT__instr)) {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            } else if ((2U & vlSelfRef.mini_rv32i__DOT__instr)) {
                if ((1U & vlSelfRef.mini_rv32i__DOT__instr)) {
                    __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                                   + vlSelfRef.mini_rv32i__DOT__pc);
                    if ((2U == (7U & (vlSelfRef.mini_rv32i__DOT__instr 
                                      >> 0xcU)))) {
                        if ((8U == (vlSelfRef.mini_rv32i__DOT__addr_s 
                                    >> 0x1cU))) {
                            __Vtask_mini_rv32i__DOT__mmio_write__0__wdata 
                                = vlSelfRef.mini_rv32i__DOT__x
                                [(0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                           >> 0x14U))];
                            __Vtask_mini_rv32i__DOT__mmio_write__0__addr 
                                = vlSelfRef.mini_rv32i__DOT__addr_s;
                            if ((0x8000000cU == __Vtask_mini_rv32i__DOT__mmio_write__0__addr)) {
                                vlSelfRef.io_out_res 
                                    = __Vtask_mini_rv32i__DOT__mmio_write__0__wdata;
                                vlSelfRef.io_out_valid = 1U;
                            }
                        } else {
                            __VdlyVal__mini_rv32i__DOT__dmem__v0 
                                = vlSelfRef.mini_rv32i__DOT__x
                                [(0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                           >> 0x14U))];
                            __VdlyDim0__mini_rv32i__DOT__dmem__v0 
                                = (0xffU & (vlSelfRef.mini_rv32i__DOT__addr_s 
                                            >> 2U));
                            __VdlySet__mini_rv32i__DOT__dmem__v0 = 1U;
                        }
                    }
                } else {
                    __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                                   + vlSelfRef.mini_rv32i__DOT__pc);
                }
            } else {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            }
        } else if ((0x10U & vlSelfRef.mini_rv32i__DOT__instr)) {
            if ((8U & vlSelfRef.mini_rv32i__DOT__instr)) {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            } else if ((4U & vlSelfRef.mini_rv32i__DOT__instr)) {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            } else if ((2U & vlSelfRef.mini_rv32i__DOT__instr)) {
                if ((1U & vlSelfRef.mini_rv32i__DOT__instr)) {
                    if ((0U == (7U & (vlSelfRef.mini_rv32i__DOT__instr 
                                      >> 0xcU)))) {
                        if ((0U != (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                             >> 7U)))) {
                            __VdlyVal__mini_rv32i__DOT__x__v35 
                                = (vlSelfRef.mini_rv32i__DOT__x
                                   [(0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                              >> 0xfU))] 
                                   + vlSelfRef.mini_rv32i__DOT__imm_i);
                            __VdlyDim0__mini_rv32i__DOT__x__v35 
                                = (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                            >> 7U));
                            __VdlySet__mini_rv32i__DOT__x__v35 = 1U;
                        }
                    }
                    __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                                   + vlSelfRef.mini_rv32i__DOT__pc);
                } else {
                    __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                                   + vlSelfRef.mini_rv32i__DOT__pc);
                }
            } else {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            }
        } else if ((8U & vlSelfRef.mini_rv32i__DOT__instr)) {
            __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                           + vlSelfRef.mini_rv32i__DOT__pc);
        } else if ((4U & vlSelfRef.mini_rv32i__DOT__instr)) {
            __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                           + vlSelfRef.mini_rv32i__DOT__pc);
        } else if ((2U & vlSelfRef.mini_rv32i__DOT__instr)) {
            if ((1U & vlSelfRef.mini_rv32i__DOT__instr)) {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
                if ((2U == (7U & (vlSelfRef.mini_rv32i__DOT__instr 
                                  >> 0xcU)))) {
                    if ((8U == (vlSelfRef.mini_rv32i__DOT__addr_i 
                                >> 0x1cU))) {
                        if ((0U != (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                             >> 7U)))) {
                            __Vfunc_mini_rv32i__DOT__mmio_read__1__addr 
                                = vlSelfRef.mini_rv32i__DOT__addr_i;
                            __Vfunc_mini_rv32i__DOT__mmio_read__1__Vfuncout 
                                = ((0x80000000U == __Vfunc_mini_rv32i__DOT__mmio_read__1__addr)
                                    ? vlSelfRef.io_in_a
                                    : ((0x80000004U 
                                        == __Vfunc_mini_rv32i__DOT__mmio_read__1__addr)
                                        ? vlSelfRef.io_in_b
                                        : ((0x80000008U 
                                            == __Vfunc_mini_rv32i__DOT__mmio_read__1__addr)
                                            ? (IData)(vlSelfRef.io_op)
                                            : 0U)));
                            __VdlyVal__mini_rv32i__DOT__x__v36 
                                = __Vfunc_mini_rv32i__DOT__mmio_read__1__Vfuncout;
                            __VdlyDim0__mini_rv32i__DOT__x__v36 
                                = (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                            >> 7U));
                            __VdlySet__mini_rv32i__DOT__x__v36 = 1U;
                        }
                    } else if ((0U != (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                                >> 7U)))) {
                        __VdlyVal__mini_rv32i__DOT__x__v37 
                            = vlSelfRef.mini_rv32i__DOT__dmem
                            [(0xffU & (vlSelfRef.mini_rv32i__DOT__addr_i 
                                       >> 2U))];
                        __VdlyDim0__mini_rv32i__DOT__x__v37 
                            = (0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                        >> 7U));
                        __VdlySet__mini_rv32i__DOT__x__v37 = 1U;
                    }
                }
            } else {
                __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                               + vlSelfRef.mini_rv32i__DOT__pc);
            }
        } else {
            __Vdly__mini_rv32i__DOT__pc = ((IData)(4U) 
                                           + vlSelfRef.mini_rv32i__DOT__pc);
        }
        __VdlySet__mini_rv32i__DOT__x__v38 = 1U;
    }
    vlSelfRef.done = __Vdly__done;
    if (__VdlySet__mini_rv32i__DOT__dmem__v0) {
        vlSelfRef.mini_rv32i__DOT__dmem[__VdlyDim0__mini_rv32i__DOT__dmem__v0] 
            = __VdlyVal__mini_rv32i__DOT__dmem__v0;
    }
    vlSelfRef.mini_rv32i__DOT__pc = __Vdly__mini_rv32i__DOT__pc;
    if (__VdlySet__mini_rv32i__DOT__x__v0) {
        vlSelfRef.mini_rv32i__DOT__x[0U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[1U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[2U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[3U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[4U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[5U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[6U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[7U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[8U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[9U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0xaU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0xbU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0xcU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0xdU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0xeU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0xfU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x10U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x11U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x12U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x13U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x14U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x15U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x16U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x17U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x18U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x19U] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x1aU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x1bU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x1cU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x1dU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x1eU] = 0U;
        vlSelfRef.mini_rv32i__DOT__x[0x1fU] = 0U;
    }
    if (__VdlySet__mini_rv32i__DOT__x__v32) {
        vlSelfRef.mini_rv32i__DOT__x[__VdlyDim0__mini_rv32i__DOT__x__v32] 
            = __VdlyVal__mini_rv32i__DOT__x__v32;
    }
    if (__VdlySet__mini_rv32i__DOT__x__v33) {
        vlSelfRef.mini_rv32i__DOT__x[__VdlyDim0__mini_rv32i__DOT__x__v33] 
            = __VdlyVal__mini_rv32i__DOT__x__v33;
    }
    if (__VdlySet__mini_rv32i__DOT__x__v34) {
        vlSelfRef.mini_rv32i__DOT__x[__VdlyDim0__mini_rv32i__DOT__x__v34] 
            = __VdlyVal__mini_rv32i__DOT__x__v34;
    }
    if (__VdlySet__mini_rv32i__DOT__x__v35) {
        vlSelfRef.mini_rv32i__DOT__x[__VdlyDim0__mini_rv32i__DOT__x__v35] 
            = __VdlyVal__mini_rv32i__DOT__x__v35;
    }
    if (__VdlySet__mini_rv32i__DOT__x__v36) {
        vlSelfRef.mini_rv32i__DOT__x[__VdlyDim0__mini_rv32i__DOT__x__v36] 
            = __VdlyVal__mini_rv32i__DOT__x__v36;
    }
    if (__VdlySet__mini_rv32i__DOT__x__v37) {
        vlSelfRef.mini_rv32i__DOT__x[__VdlyDim0__mini_rv32i__DOT__x__v37] 
            = __VdlyVal__mini_rv32i__DOT__x__v37;
    }
    if (__VdlySet__mini_rv32i__DOT__x__v38) {
        vlSelfRef.mini_rv32i__DOT__x[0U] = 0U;
    }
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

void Vmini_rv32i___024root___eval_triggers__act(Vmini_rv32i___024root* vlSelf);

bool Vmini_rv32i___024root___eval_phase__act(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_phase__act\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmini_rv32i___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vmini_rv32i___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmini_rv32i___024root___eval_phase__nba(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_phase__nba\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmini_rv32i___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmini_rv32i___024root___dump_triggers__nba(Vmini_rv32i___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmini_rv32i___024root___dump_triggers__act(Vmini_rv32i___024root* vlSelf);
#endif  // VL_DEBUG

void Vmini_rv32i___024root___eval(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vmini_rv32i___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/mini_rv32i.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vmini_rv32i___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/mini_rv32i.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vmini_rv32i___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vmini_rv32i___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmini_rv32i___024root___eval_debug_assertions(Vmini_rv32i___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root___eval_debug_assertions\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY(((vlSelfRef.io_op & 0xfcU)))) {
        Verilated::overWidthError("io_op");}
}
#endif  // VL_DEBUG
