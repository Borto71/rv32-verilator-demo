#include <verilated.h>
#include "Vmini_rv32i.h"

#if VM_TRACE
# include <verilated_fst_c.h>
#endif

static vluint64_t sim_time = 0; // tempo di simulazione
double sc_time_stamp() { return sim_time; } // per SystemC

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv); // gestisce i parametri della riga di comando
  Vmini_rv32i* top = new Vmini_rv32i; // istanzia il modulo di top-level

#if VM_TRACE // Abilita la generazione del file di traccia
  Verilated::traceEverOn(true);
  VerilatedFstC* tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open("build/trace.fst");
#endif

  // --- Test case ---
  uint32_t A  = 21;
  uint32_t B  = 9;
  uint32_t OP = 0;   // 0=ADD, 1=SUB

  // Reset + set MMIO inputs
  top -> io_in_a = A;
  top -> io_in_b = B;
  top -> io_op   = OP;

  top->rst = 1; // attiva il reset
  for (int i=0; i<4; i++) { // 4 cicli di clock con reset attivo
    top->clk = 0; top->eval(); sim_time++;
#if VM_TRACE
    tfp->dump(sim_time);
#endif
    top->clk = 1; top->eval(); sim_time++;
#if VM_TRACE
    tfp->dump(sim_time);
#endif
  }
  top->rst = 0;

  const int MAX_CYCLES = 2000; // per evitare cicli infiniti
  for (int i=0; i<MAX_CYCLES && !top->done; i++) { // cicla finché done non va a 1
    top->clk = 0; top->eval(); sim_time++; // fronte di salita del clock
#if VM_TRACE
    tfp->dump(sim_time);
#endif
    top->clk = 1; top->eval(); sim_time++;
#if VM_TRACE
    tfp->dump(sim_time);
#endif
  }

  printf("Program finished. x3 = %u (0x%08x)\n", top->x3_out, top -> x3_out);
  if (top -> io_out_valid) {
    printf("MMIO result = %u (0x%08x)\n", top -> io_out_res, top -> io_out_res);
  } else {
    printf("MMIO result not written.\n");
  }

#if VM_TRACE
  tfp->close();
  delete tfp;
#endif
  top->final();
  delete top;
  return 0;
}
