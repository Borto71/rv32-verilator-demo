// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vmini_rv32i__Syms.h"


void Vmini_rv32i___024root__trace_chg_0_sub_0(Vmini_rv32i___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vmini_rv32i___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_chg_0\n"); );
    // Init
    Vmini_rv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmini_rv32i___024root*>(voidSelf);
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmini_rv32i___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vmini_rv32i___024root__trace_chg_0_sub_0(Vmini_rv32i___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_chg_0_sub_0\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.mini_rv32i__DOT__x[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.mini_rv32i__DOT__x[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.mini_rv32i__DOT__x[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.mini_rv32i__DOT__x[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.mini_rv32i__DOT__x[4]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.mini_rv32i__DOT__x[5]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.mini_rv32i__DOT__x[6]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.mini_rv32i__DOT__x[7]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.mini_rv32i__DOT__x[8]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.mini_rv32i__DOT__x[9]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.mini_rv32i__DOT__x[10]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.mini_rv32i__DOT__x[11]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.mini_rv32i__DOT__x[12]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.mini_rv32i__DOT__x[13]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.mini_rv32i__DOT__x[14]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.mini_rv32i__DOT__x[15]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.mini_rv32i__DOT__x[16]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.mini_rv32i__DOT__x[17]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.mini_rv32i__DOT__x[18]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.mini_rv32i__DOT__x[19]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.mini_rv32i__DOT__x[20]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.mini_rv32i__DOT__x[21]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.mini_rv32i__DOT__x[22]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.mini_rv32i__DOT__x[23]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.mini_rv32i__DOT__x[24]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.mini_rv32i__DOT__x[25]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.mini_rv32i__DOT__x[26]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.mini_rv32i__DOT__x[27]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.mini_rv32i__DOT__x[28]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.mini_rv32i__DOT__x[29]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.mini_rv32i__DOT__x[30]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.mini_rv32i__DOT__x[31]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.mini_rv32i__DOT__pc),32);
        bufp->chgIData(oldp+33,(vlSelfRef.mini_rv32i__DOT__instr),32);
        bufp->chgCData(oldp+34,((0x7fU & vlSelfRef.mini_rv32i__DOT__instr)),7);
        bufp->chgCData(oldp+35,((7U & (vlSelfRef.mini_rv32i__DOT__instr 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+36,((vlSelfRef.mini_rv32i__DOT__instr 
                                 >> 0x19U)),7);
        bufp->chgCData(oldp+37,((0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+38,((0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+39,((0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                          >> 7U))),5);
        bufp->chgIData(oldp+40,(vlSelfRef.mini_rv32i__DOT__imm_i),32);
        bufp->chgIData(oldp+41,((((- (IData)((vlSelfRef.mini_rv32i__DOT__instr 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelfRef.mini_rv32i__DOT__instr 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.mini_rv32i__DOT__instr 
                                                    >> 7U))))),32);
        bufp->chgIData(oldp+42,((0xfffff000U & vlSelfRef.mini_rv32i__DOT__instr)),32);
        bufp->chgIData(oldp+43,((((- (IData)((vlSelfRef.mini_rv32i__DOT__instr 
                                              >> 0x1fU))) 
                                  << 0xdU) | ((((2U 
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
                                                       >> 7U)))))),32);
        bufp->chgIData(oldp+44,(vlSelfRef.mini_rv32i__DOT__addr_i),32);
        bufp->chgIData(oldp+45,(vlSelfRef.mini_rv32i__DOT__addr_s),32);
        bufp->chgIData(oldp+46,(vlSelfRef.mini_rv32i__DOT__i),32);
    }
    bufp->chgBit(oldp+47,(vlSelfRef.clk));
    bufp->chgBit(oldp+48,(vlSelfRef.rst));
    bufp->chgIData(oldp+49,(vlSelfRef.io_in_a),32);
    bufp->chgIData(oldp+50,(vlSelfRef.io_in_b),32);
    bufp->chgCData(oldp+51,(vlSelfRef.io_op),2);
    bufp->chgIData(oldp+52,(vlSelfRef.io_out_res),32);
    bufp->chgBit(oldp+53,(vlSelfRef.io_out_valid));
    bufp->chgIData(oldp+54,(vlSelfRef.x3_out),32);
    bufp->chgBit(oldp+55,(vlSelfRef.done));
}

void Vmini_rv32i___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_cleanup\n"); );
    // Init
    Vmini_rv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmini_rv32i___024root*>(voidSelf);
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
