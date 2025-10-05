#include <verilated.h>
#include "Vmini_rv32i.h"
#if VM_TRACE
# include <verilated_fst_c.h>
#endif

static vluint64_t sim_time = 0;
double sc_time_stamp() { return sim_time; }

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  Vmini_rv32i* top = new Vmini_rv32i;

#if VM_TRACE
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

  top->rst = 1;
  for (int i=0; i<4; i++) {
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

  const int MAX_CYCLES = 2000;
  for (int i=0; i<MAX_CYCLES && !top->done; i++) {
    top->clk = 0; top->eval(); sim_time++;
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
