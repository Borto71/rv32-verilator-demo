#include <verilated.h>
#include "Vmini_rv32i.h"

#if VM_TRACE
# include <verilated_fst_c.h>
# define TRACE_PASS_ARG , tfp
#else
# define TRACE_PASS_ARG
#endif

#include <cstdint>

// Struttura di supporto per descrivere ogni scenario di test
struct TestCase {
  const char* nome;
  uint32_t    a;
  uint32_t    b;
  uint32_t    op;
  uint32_t    risultato_atteso;
};

// Tabella di stimoli: op=0 somma, op=1 sottrazione, valori fuori range servono a verificare la scelta di default
static const TestCase kTestCases[] = {
  {"Somma base",          21u,         9u,         0u,  30u},
  {"Sottrazione negativa", 9u,         21u,        1u,  0xFFFFFFF4u},
  {"Overflow somma",      0xFFFF0000u, 0x0000FFFFu, 0u,  0xFFFFFFFFu},
  {"Somma di default",    5u,          7u,         2u,  12u},
  {"Sottrazione a zero",  0x12345678u, 0x12345678u, 1u,  0u}
};

static constexpr int kNumTests   = sizeof(kTestCases) / sizeof(kTestCases[0]);
static constexpr int kMaxCycles  = 4096;   // limite di sicurezza per la simulazione
static vluint64_t    sim_time    = 0;      // tempo di simulazione condiviso

// Ritorna il tempo corrente (richiesto dall'infrastruttura Verilator)
double sc_time_stamp() { return sim_time; }

// Esegue un intero ciclo di clock (clk=0 -> clk=1) aggiornando la traccia se abilitata
inline void tick(Vmini_rv32i* top
#if VM_TRACE
                 , VerilatedFstC* tfp
#endif
                 ) {
  top->clk = 0;
  top->eval();
  sim_time++;
#if VM_TRACE
  if (tfp) tfp->dump(sim_time);
#endif

  top->clk = 1;
  top->eval();
  sim_time++;
#if VM_TRACE
  if (tfp) tfp->dump(sim_time);
#endif
}

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv); // gestisce i parametri della riga di comando
  Vmini_rv32i* top = new Vmini_rv32i; // istanzia il modulo di top-level

#if VM_TRACE // Abilita la generazione del file di traccia
  Verilated::traceEverOn(true);
  VerilatedFstC* tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open("build/trace_strong.fst");
#endif

  bool tutti_ok = true; // accumula l'esito globale della campagna di test

  for (int idx = 0; idx < kNumTests; ++idx) {
    const TestCase& test = kTestCases[idx];

    // Configura gli ingressi MMIO prima del rilascio del reset
    top->io_in_a = test.a;
    top->io_in_b = test.b;
    top->io_op   = test.op;

    top->rst = 1; // tieni il core in reset per alcuni cicli per garantire lo stato noto
    for (int i = 0; i < 4; ++i) {
      tick(top TRACE_PASS_ARG);
    }
    top->rst = 0;

    bool done_rilevato = false;
    for (int ciclo = 0; ciclo < kMaxCycles; ++ciclo) {
      tick(top TRACE_PASS_ARG);
      if (top->done) {
        done_rilevato = true;
        break;
      }
    }

    if (!done_rilevato) {
      printf("[TEST %d - %s] Timeout: segnale 'done' mai attivato\n", idx + 1, test.nome);
      tutti_ok = false;
    } else {
      const uint32_t risultato = top->io_out_res;
      const uint32_t reg_x3    = top->x3_out;
      const bool     valido    = top->io_out_valid;

      bool test_ok = true;
      if (!valido) {
        printf("[TEST %d - %s] ERRORE: 'io_out_valid' non attivo\n", idx + 1, test.nome);
        test_ok = false;
      }
      if (risultato != test.risultato_atteso) {
        printf("[TEST %d - %s] ERRORE: risultato MMIO 0x%08x atteso 0x%08x\n",
               idx + 1, test.nome, risultato, test.risultato_atteso);
        test_ok = false;
      }
      if (reg_x3 != test.risultato_atteso) {
        printf("[TEST %d - %s] ERRORE: registro x3 0x%08x atteso 0x%08x\n",
               idx + 1, test.nome, reg_x3, test.risultato_atteso);
        test_ok = false;
      }

      if (test_ok) {
        printf("[TEST %d - %s] OK: risultato 0x%08x, op=%u\n",
               idx + 1, test.nome, risultato, test.op);
      } else {
        tutti_ok = false;
      }
    }

    // Riporta il core in reset per "pulire" lo stato prima del test successivo
    top->rst = 1;
    for (int i = 0; i < 2; ++i) {
      tick(top TRACE_PASS_ARG);
    }
    top->rst = 0;
    tick(top TRACE_PASS_ARG); // un ciclo extra per stabilizzare gli output dopo il reset
  }

  if (tutti_ok) {
    printf("\nTUTTI I TEST SONO PASSATI\n");
  } else {
    printf("\nALCUNI TEST SONO FALLITI\n");
  }

#if VM_TRACE
  tfp->close();
  delete tfp;
#endif
  top->final();
  delete top;
  return tutti_ok ? 0 : 1;
}
