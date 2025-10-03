// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmini_rv32i__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vmini_rv32i::Vmini_rv32i(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmini_rv32i__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , io_op{vlSymsp->TOP.io_op}
    , io_out_valid{vlSymsp->TOP.io_out_valid}
    , done{vlSymsp->TOP.done}
    , io_in_a{vlSymsp->TOP.io_in_a}
    , io_in_b{vlSymsp->TOP.io_in_b}
    , io_out_res{vlSymsp->TOP.io_out_res}
    , x3_out{vlSymsp->TOP.x3_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmini_rv32i::Vmini_rv32i(const char* _vcname__)
    : Vmini_rv32i(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmini_rv32i::~Vmini_rv32i() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmini_rv32i___024root___eval_debug_assertions(Vmini_rv32i___024root* vlSelf);
#endif  // VL_DEBUG
void Vmini_rv32i___024root___eval_static(Vmini_rv32i___024root* vlSelf);
void Vmini_rv32i___024root___eval_initial(Vmini_rv32i___024root* vlSelf);
void Vmini_rv32i___024root___eval_settle(Vmini_rv32i___024root* vlSelf);
void Vmini_rv32i___024root___eval(Vmini_rv32i___024root* vlSelf);

void Vmini_rv32i::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmini_rv32i::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmini_rv32i___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmini_rv32i___024root___eval_static(&(vlSymsp->TOP));
        Vmini_rv32i___024root___eval_initial(&(vlSymsp->TOP));
        Vmini_rv32i___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmini_rv32i___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmini_rv32i::eventsPending() { return false; }

uint64_t Vmini_rv32i::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmini_rv32i::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmini_rv32i___024root___eval_final(Vmini_rv32i___024root* vlSelf);

VL_ATTR_COLD void Vmini_rv32i::final() {
    Vmini_rv32i___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmini_rv32i::hierName() const { return vlSymsp->name(); }
const char* Vmini_rv32i::modelName() const { return "Vmini_rv32i"; }
unsigned Vmini_rv32i::threads() const { return 1; }
void Vmini_rv32i::prepareClone() const { contextp()->prepareClone(); }
void Vmini_rv32i::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmini_rv32i::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmini_rv32i___024root__trace_decl_types(VerilatedFst* tracep);

void Vmini_rv32i___024root__trace_init_top(Vmini_rv32i___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmini_rv32i___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmini_rv32i___024root*>(voidSelf);
    Vmini_rv32i__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmini_rv32i___024root__trace_decl_types(tracep);
    Vmini_rv32i___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmini_rv32i___024root__trace_register(Vmini_rv32i___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vmini_rv32i::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmini_rv32i::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmini_rv32i___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
