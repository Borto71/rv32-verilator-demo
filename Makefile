# --- Toolchain ---
VERILATOR ?= verilator
RISCV     ?= riscv-none-elf

AS      := $(RISCV)-as
CC      := $(RISCV)-gcc
OBJCOPY := $(RISCV)-objcopy

TOP       = mini_rv32i
BUILD_DIR = build
RTL       = rtl/mini_rv32i.v
TB        = sim/main.cpp
BIN       = $(BUILD_DIR)/sim

# Sorgenti firmware
FW_ASM   = firmware/prog.S
FW_C     = firmware/main.c

FW_ELF   = $(BUILD_DIR)/prog.elf
FW_O     = $(BUILD_DIR)/prog.o
FW_BIN   = $(BUILD_DIR)/prog.bin
FW_HEX   = firmware/prog.hex

FW_CFLAGS  = -march=rv32i -mabi=ilp32 -nostdlib -Os -ffreestanding
FW_LDFLAGS = -Wl,--no-relax -Wl,-Ttext=0x0

WAVES ?= 0
TRACE_FLAGS =
ifeq ($(WAVES),1)
TRACE_FLAGS = --trace-fst --trace-structs
endif

.PHONY: all run clean waves

all: $(BIN)

# Se c'è prog.S usa ASM, altrimenti se c'è main.c usa C
ifeq ($(wildcard $(FW_ASM)), $(FW_ASM))
$(FW_O): $(FW_ASM)
	@mkdir -p $(BUILD_DIR)
	$(AS) -march=rv32i -mabi=ilp32 -o $@ $<
$(FW_BIN): $(FW_O)
	$(OBJCOPY) -O binary $< $@
else ifeq ($(wildcard $(FW_C)), $(FW_C))
$(FW_ELF): $(FW_C)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FW_CFLAGS) $(FW_LDFLAGS) -o $@ $<
$(FW_BIN): $(FW_ELF)
	$(OBJCOPY) -O binary $< $@
else
$(error "Metti firmware/prog.S o firmware/main.c")
endif

# BIN -> HEX 32-bit per riga
$(FW_HEX): $(FW_BIN) firmware/bin2hex32.py
	python3 firmware/bin2hex32.py $(FW_BIN) $(FW_HEX)

# Build simulatore Verilator (dipende dall'HEX)
$(BIN): $(RTL) $(TB) $(FW_HEX)
	@mkdir -p $(BUILD_DIR)
	$(VERILATOR) -Wall $(TRACE_FLAGS) --cc $(RTL) --exe $(TB) \
	  -O3 -CFLAGS "-std=c++17" \
	  --build -Mdir $(BUILD_DIR) -o sim

run: $(BIN)
	./$(BIN)

waves:
	$(MAKE) WAVES=1 all
	./$(BIN)
	@echo "Apro onde con GTKWave: gtkwave $(BUILD_DIR)/trace.fst &"

clean:
	rm -rf $(BUILD_DIR) $(FW_HEX)
