    .section .text
    .globl _start
_start:
    # x10 = 0x80000000 (MMIO base)
    lui   x10, 0x80000

    # Leggi A, B, OP da MMIO
    lw    x1,  0(x10)      # x1 <- A
    lw    x2,  4(x10)      # x2 <- B
    lw    x4,  8(x10)      # x4 <- OP (0=ADD, 1=SUB)

    # if (OP == 0) goto DO_ADD
    addi  x5, x0, 0
    beq   x4, x5, DO_ADD

    # if (OP == 1) goto DO_SUB
    addi  x5, x0, 1
    beq   x4, x5, DO_SUB

    # default: ADD
DO_ADD:
    add   x3, x1, x2
    sw    x3, 12(x10)      # RES <- x3
    ebreak

DO_SUB:
    sub   x3, x1, x2
    sw    x3, 12(x10)      # RES <- x3
    ebreak
