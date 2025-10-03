// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMINI_RV32I__SYMS_H_
#define VERILATED_VMINI_RV32I__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmini_rv32i.h"

// INCLUDE MODULE CLASSES
#include "Vmini_rv32i___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vmini_rv32i__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmini_rv32i* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmini_rv32i___024root          TOP;

    // CONSTRUCTORS
    Vmini_rv32i__Syms(VerilatedContext* contextp, const char* namep, Vmini_rv32i* modelp);
    ~Vmini_rv32i__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
