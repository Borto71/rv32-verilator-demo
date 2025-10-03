# Mini RISC-V + Verilator Demo

A **minimal educational project** to simulate a **single-cycle RISC-V core** with **Verilator**.  
The firmware reads two operands and an operation code from **MMIO** (`0x8000_0000`), performs **ADD** or **SUB**, writes the result back to MMIO, and terminates with `EBREAK`.  
Supports **waveforms** with GTKWave (FST).

---

## Project Structure

```
rv32-verilator-demo/
├─ rtl/
│  └─ mini_rv32i.v          # RV32I single-cycle core with DMEM + MMIO
├─ sim/
│  └─ main.cpp              # Verilator C++ testbench (clock/reset, MMIO I/O)
├─ firmware/
│  ├─ prog.S                # Example firmware (Assembly)
│  └─ bin2hex32.py          # BIN → HEX (32-bit/word) for $readmemh
└─ Makefile                 # Build firmware + simulator (+ waveforms)
```

---

## Requirements

- **Verilator** (>= 5.x) in `PATH`
- **GNU C++** (g++), `make`, `python3`
- **GTKWave** (`sudo apt install -y gtkwave`)
- **RISC-V bare-metal toolchain** (xPack recommended):
  - `riscv-none-elf-gcc`, `riscv-none-elf-as`, `riscv-none-elf-objcopy`, …

### RISC-V Toolchain Installation (xPack, WSL/Ubuntu)

```bash
# 1) Install xpm if missing
sudo apt update
sudo apt install -y nodejs npm
npm install --global xpm

# 2) Install toolchain
xpm install --global @xpack-dev-tools/riscv-none-elf-gcc@latest

# 3) Update PATH (add one line to ~/.bashrc or ~/.zshrc)
echo 'export PATH="$HOME/.local/xPacks/@xpack-dev-tools/riscv-none-elf-gcc/14.2.0-3.1/.content/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
which riscv-none-elf-gcc && riscv-none-elf-gcc --version
```

> Alternatively, on some Ubuntu versions:  
> `sudo apt install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf`  
> (then use `riscv64-unknown-elf-*` instead of `riscv-none-elf-*`).

---

## Quickstart

From the project root:

```bash
make          # build firmware + simulator
make run      # run simulation
# Expected output:
# Program finished. x3 = 30 (0x0000001e)
# MMIO result = 30 (0x0000001e)
```

### Waveforms (GTKWave)

**Safe method (always recompile with trace):**
```bash
make clean
make WAVES=1 all
./build/sim
gtkwave build/trace.fst &
```

> If your `Makefile` has a `waves` target (clean+trace+run+open):
> ```bash
> make waves
> ```
> Otherwise, use the 4 commands above.

---

## Firmware Build Pipeline

- **Sources**: you can use **Assembly** (`firmware/prog.S`) or **C** (`firmware/main.c`, optional).  
- **Makefile pipeline**:
  1. `as/cc` → object or ELF
  2. `objcopy -O binary` → `prog.bin`
  3. `bin2hex32.py` → `firmware/prog.hex` (32-bit words, hex)

The core loads `firmware/prog.hex` into **instruction ROM** via `$readmemh`.

Why not `-O verilog`? Because it produces byte-wise HEX with markers, incompatible with `$readmemh` on word arrays.

---

## RTL: `rtl/mini_rv32i.v` (summary)

- **Single-cycle** RV32I core.
- **Instruction ROM**: `imem[0:255]` (1 KiB), indexed by `pc[9:2]`.
- **Data memory**: `dmem[0:255]` (1 KiB) for `LW/SW` not in MMIO space.
- **MMIO base** `0x8000_0000`:
  - `0x8000_0000` → A (ro)
  - `0x8000_0004` → B (ro)
  - `0x8000_0008` → OP (ro) — `0=ADD`, `1=SUB`
  - `0x8000_000C` → RES (wo)
- **Supported instructions**: `LUI`, `ADDI`, `ADD`, `SUB`, `LW`, `SW`, `BEQ`, `EBREAK`.
- **Termination**: `EBREAK` (imm=1) → `done=1`, `x3_out <= x3`.
- **Note**: `x0` is forced to zero each cycle (`x[0] <= 0`).

---

## Firmware Example (`firmware/prog.S`)

```asm
lui   x10, 0x80000      # x10 = 0x80000000 (MMIO base)
lw    x1,  0(x10)       # A
lw    x2,  4(x10)       # B
lw    x4,  8(x10)       # OP (0 add, 1 sub)

addi  x5, x0, 0
beq   x4, x5, DO_ADD
addi  x5, x0, 1
beq   x4, x5, DO_SUB

DO_ADD:
  add  x3, x1, x2
  sw   x3, 12(x10)      # RES = x3
  ebreak

DO_SUB:
  sub  x3, x1, x2
  sw   x3, 12(x10)
  ebreak
```

---

## Testbench (`sim/main.cpp`)

- Sets MMIO inputs before releasing reset:
  ```cpp
  uint32_t A = 21, B = 9, OP = 0; // 0=ADD, 1=SUB
  top->io_in_a = A;
  top->io_in_b = B;
  top->io_op   = OP;
  ```
- Runs clock/reset, waits for `done`, prints `x3_out` and `io_out_res`.
- With `WAVES=1`, produces `build/trace.fst`.

---

## Waveforms: What to Observe

- `pc`, `instr`, `done`
- `x3_out`, `io_out_res`, `io_out_valid`
- `opcode`, `funct3`, `funct7`, `imm_i/imm_s/imm_b/imm_u`
- GPR registers (`x[0]..x[31]`) — visible as Verilator internal signals.

> Tip: Save a setup with `File → Write Save File…` in GTKWave for quick reload.

---

## Troubleshooting

**Verilator not found**
```bash
verilator --version
```

**RISC-V toolchain not found**
```bash
which riscv-none-elf-gcc
riscv-none-elf-gcc --version
```

**GTKWave: “Could not initialize 'build/trace.fst'”**
- Probably compiled **without** tracing.  
  Solution:
  ```bash
  make clean
  make WAVES=1 all
  ./build/sim
  gtkwave build/trace.fst &
  ```

**“Nothing to be done for 'all'” but no trace**
- Old build reused. Run `make clean` before `WAVES=1`.

---

## Suggested Extensions

- Add ALU ops: `AND`, `OR`, `XOR`, `SLT`, … mapped to new `io_op` codes.
- Make `io_out_valid` a **1-cycle pulse** (clear at start of cycle, set only on MMIO write).
- Add more branches (`BNE`, `BLT`, …) and jumps (`JAL`, `JALR`) for loops/calls.
- Add realistic I/O devices (UART, FIFO) via MMIO.

---

## Useful Commands

```bash
make && make run                      # Build + run
make clean && make && make run        # Rebuild firmware after edits
make clean && make WAVES=1 all && ./build/sim && gtkwave build/trace.fst &
make clean                            # Full cleanup
```

---

## License

This project is for educational purposes. Use and modify freely, respecting the licenses of used tools (Verilator, xPack, GTKWave).
