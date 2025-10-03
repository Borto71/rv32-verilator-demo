// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vmini_rv32i__Syms.h"


VL_ATTR_COLD void Vmini_rv32i___024root__trace_init_sub__TOP__0(Vmini_rv32i___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_init_sub__TOP__0\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+48,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"io_in_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"io_in_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"io_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+53,0,"io_out_res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+54,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"x3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mini_rv32i", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+48,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"io_in_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"io_in_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"io_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+53,0,"io_out_res",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+54,0,"io_out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"x3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("x", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+33,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+36,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+37,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+38,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"imm_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"imm_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"MMIO_BASE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"MMIO_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"MMIO_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"MMIO_OP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"MMIO_RES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"addr_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"addr_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmini_rv32i___024root__trace_init_top(Vmini_rv32i___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_init_top\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmini_rv32i___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmini_rv32i___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vmini_rv32i___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vmini_rv32i___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vmini_rv32i___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vmini_rv32i___024root__trace_register(Vmini_rv32i___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_register\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vmini_rv32i___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vmini_rv32i___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vmini_rv32i___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vmini_rv32i___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmini_rv32i___024root__trace_const_0_sub_0(Vmini_rv32i___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vmini_rv32i___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_const_0\n"); );
    // Init
    Vmini_rv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmini_rv32i___024root*>(voidSelf);
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmini_rv32i___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmini_rv32i___024root__trace_const_0_sub_0(Vmini_rv32i___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_const_0_sub_0\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+57,(0x80000000U),32);
    bufp->fullIData(oldp+58,(0x80000004U),32);
    bufp->fullIData(oldp+59,(0x80000008U),32);
    bufp->fullIData(oldp+60,(0x8000000cU),32);
}

VL_ATTR_COLD void Vmini_rv32i___024root__trace_full_0_sub_0(Vmini_rv32i___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vmini_rv32i___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_full_0\n"); );
    // Init
    Vmini_rv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmini_rv32i___024root*>(voidSelf);
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmini_rv32i___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmini_rv32i___024root__trace_full_0_sub_0(Vmini_rv32i___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmini_rv32i___024root__trace_full_0_sub_0\n"); );
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.mini_rv32i__DOT__x[0]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.mini_rv32i__DOT__x[1]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.mini_rv32i__DOT__x[2]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.mini_rv32i__DOT__x[3]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.mini_rv32i__DOT__x[4]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.mini_rv32i__DOT__x[5]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.mini_rv32i__DOT__x[6]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.mini_rv32i__DOT__x[7]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.mini_rv32i__DOT__x[8]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.mini_rv32i__DOT__x[9]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.mini_rv32i__DOT__x[10]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.mini_rv32i__DOT__x[11]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.mini_rv32i__DOT__x[12]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.mini_rv32i__DOT__x[13]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.mini_rv32i__DOT__x[14]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.mini_rv32i__DOT__x[15]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.mini_rv32i__DOT__x[16]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.mini_rv32i__DOT__x[17]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.mini_rv32i__DOT__x[18]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.mini_rv32i__DOT__x[19]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.mini_rv32i__DOT__x[20]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.mini_rv32i__DOT__x[21]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.mini_rv32i__DOT__x[22]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.mini_rv32i__DOT__x[23]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.mini_rv32i__DOT__x[24]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.mini_rv32i__DOT__x[25]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.mini_rv32i__DOT__x[26]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.mini_rv32i__DOT__x[27]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.mini_rv32i__DOT__x[28]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.mini_rv32i__DOT__x[29]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.mini_rv32i__DOT__x[30]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.mini_rv32i__DOT__x[31]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.mini_rv32i__DOT__pc),32);
    bufp->fullIData(oldp+34,(vlSelfRef.mini_rv32i__DOT__instr),32);
    bufp->fullCData(oldp+35,((0x7fU & vlSelfRef.mini_rv32i__DOT__instr)),7);
    bufp->fullCData(oldp+36,((7U & (vlSelfRef.mini_rv32i__DOT__instr 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+37,((vlSelfRef.mini_rv32i__DOT__instr 
                              >> 0x19U)),7);
    bufp->fullCData(oldp+38,((0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+39,((0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+40,((0x1fU & (vlSelfRef.mini_rv32i__DOT__instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+41,(vlSelfRef.mini_rv32i__DOT__imm_i),32);
    bufp->fullIData(oldp+42,((((- (IData)((vlSelfRef.mini_rv32i__DOT__instr 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelfRef.mini_rv32i__DOT__instr 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelfRef.mini_rv32i__DOT__instr 
                                                 >> 7U))))),32);
    bufp->fullIData(oldp+43,((0xfffff000U & vlSelfRef.mini_rv32i__DOT__instr)),32);
    bufp->fullIData(oldp+44,((((- (IData)((vlSelfRef.mini_rv32i__DOT__instr 
                                           >> 0x1fU))) 
                               << 0xdU) | ((((2U & 
                                              (vlSelfRef.mini_rv32i__DOT__instr 
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
    bufp->fullIData(oldp+45,(vlSelfRef.mini_rv32i__DOT__addr_i),32);
    bufp->fullIData(oldp+46,(vlSelfRef.mini_rv32i__DOT__addr_s),32);
    bufp->fullIData(oldp+47,(vlSelfRef.mini_rv32i__DOT__i),32);
    bufp->fullBit(oldp+48,(vlSelfRef.clk));
    bufp->fullBit(oldp+49,(vlSelfRef.rst));
    bufp->fullIData(oldp+50,(vlSelfRef.io_in_a),32);
    bufp->fullIData(oldp+51,(vlSelfRef.io_in_b),32);
    bufp->fullCData(oldp+52,(vlSelfRef.io_op),2);
    bufp->fullIData(oldp+53,(vlSelfRef.io_out_res),32);
    bufp->fullBit(oldp+54,(vlSelfRef.io_out_valid));
    bufp->fullIData(oldp+55,(vlSelfRef.x3_out),32);
    bufp->fullBit(oldp+56,(vlSelfRef.done));
}
