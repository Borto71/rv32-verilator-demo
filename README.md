# Mini RISC-V Simulation Demo

Educational setup for a **single-cycle RV32I core** that can be simulated with either **Verilator** (C++ testbench) or **Icarus Verilog** (pure Verilog testbench). The firmware reads two operands and an opcode from MMIO (`0x8000_0000`), performs an ADD/SUB, writes the result back, then halts with `EBREAK`.

---

## Project Layout

```
rv32-verilator-demo/
├─ rtl/
│  └─ mini_rv32i.v          # RV32I core with DMEM + MMIO
├─ sim/
│  ├─ main.cpp              # Verilator C++ testbench
│  └─ tb.v                  # Icarus Verilog testbench
├─ firmware/
│  ├─ prog.S                # Example firmware (assembly)
│  └─ bin2hex32.py          # BIN → HEX (word-wide) for $readmemh
├─ Makefile                 # Default (Verilator) build
└─ Makefile2                # Icarus-oriented build
```

---

## Requirements

- RISC-V bare-metal toolchain (`riscv-none-elf-*`)
- Python 3
- GNU Make + g++
- Verilator ≥ 5.x
- Icarus Verilog (`iverilog`, `vvp`)
- GTKWave (optional but handy)

### RISC-V Toolchain (xPack on Ubuntu/WSL)

```bash
sudo apt update
sudo apt install -y nodejs npm python3 make g++
npm install --global xpm
xpm install --global @xpack-dev-tools/riscv-none-elf-gcc@latest
echo 'export PATH="$HOME/.local/xPacks/@xpack-dev-tools/riscv-none-elf-gcc/*/.content/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
riscv-none-elf-gcc --version
```

Alternative distro packages:

```bash
sudo apt install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf
# then export RISCV=riscv64-unknown-elf before invoking make
```

---

## Quickstart

### Verilator flow (C++ testbench)

```bash
# build firmware + Verilator simulator
make

# run
make run
# Expected:
# Program finished. x3 = 30 (0x0000001e)
# MMIO result = 30 (0x0000001e)
```

### Icarus flow (Verilog testbench)

```bash
# clean + rebuild + run using Makefile2
make -f Makefile2 clean
make -f Makefile2 icarus
# Program finished. x3 = 30 (0x0000001e)
# MMIO result = 30 (0x0000001e)
```

Tip for timing comparisons:

```bash
/usr/bin/time -f "real %E" make run
/usr/bin/time -f "real %E" make -f Makefile2 icarus
```

---

## Waveform Capture

- **Verilator** (`build/trace.fst`)
  ```bash
  make clean
  make WAVES=1 all
  ./build/sim
  gtkwave build/trace.fst &
  ```
  (`make waves` is a shortcut for the same sequence.)

- **Icarus** (`build/icarus_trace.vcd`)
  ```bash
  make -f Makefile2 waves
  # automatically runs vvp and tries to open GTKWave
  ```
  On headless hosts set `DISPLAY` or skip the viewer by running only
  `make -f Makefile2 icarus`.

Signals worth inspecting: `pc`, `instr`, `done`, `io_out_res`, `io_out_valid`, register file contents, and decoded immediates.

---

## Firmware Flow

1. Assemble/compile (`riscv-none-elf-as` or `riscv-none-elf-gcc`).
2. Convert to raw binary (`objcopy -O binary`).
3. Convert to hexadecimal words (`bin2hex32.py`) → `firmware/prog.hex`.

The ROM loader uses `$readmemh("firmware/prog.hex", imem);`. Truncation warnings from Icarus simply mean `prog.hex` is shorter than the 1 KiB ROM, which is expected for small programs.

---

## Core Overview (`rtl/mini_rv32i.v`)

- Single-cycle RV32I subset (`LUI`, `ADDI`, `ADD`, `SUB`, `LW`, `SW`, `BEQ`, `EBREAK`).
- Instruction memory: `imem[0:255]` (1 KiB).
- Data memory: `dmem[0:255]` (1 KiB).
- MMIO window at `0x8000_0000` for operands, opcode, and result.
- `done` asserts on `EBREAK imm=1`, and `x3_out` exposes register `x3`.
- `x0` is forced to zero every clock to maintain ISA semantics.

---

## Testbenches

- `sim/main.cpp`: Verilator harness in C++. Sets MMIO inputs, generates a clock for up to 2000 cycles, prints `x3_out` and the MMIO result. Supports FST tracing when `WAVES=1`.
- `sim/tb.v`: Pure-Verilog harness for Icarus. Drives the same stimulus, generates a VCD (`build/icarus_trace.vcd`), and stops when `done` asserts.

Both share the same firmware image (`firmware/prog.hex`).

---

## Troubleshooting

- `make: riscv-none-elf-gcc: No such file or directory` → ensure the toolchain is installed and `RISCV` is set appropriately.
- `verilator: command not found` → install Verilator (`sudo apt install verilator`) or adjust PATH.
- `iverilog: command not found` → install Icarus Verilog (`sudo apt install iverilog`).
- GTKWave fails with *Could not initialize GTK* on headless servers → either export `DISPLAY` to a running X server or skip the viewer.
- `$readmemh: Not enough words` → benign unless you expect the firmware to use the entire ROM.

---

## Useful Commands

### Build & Run with Verilator
```bash
make && make run
```
Runs the project using **Verilator**.

### Verilator Waveform Flow
```bash
make clean && make WAVES=1 all && ./build/sim
```
Clean execution, generates the **waveform (VCD)** and start the simulation on Verilator.

### Build & Run with Icarus Verilog
```bash
make -f Makefile2 icarus
```
Compile and execute simulation on **Icarus Verilog**.

### Icarus Waveform Flow
```bash
make -f Makefile2 waves
```
Execute the simulation with Icarus Verilog and generates the **waveform** for analysis.

---

## Reference

For documentation you can check:
[RISC-V ISA Documentation](https://msyksphinz-self.github.io/riscv-isadoc/html/rvi.html)


## License

This project is licensed under the **MIT License**. 
