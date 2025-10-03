#!/usr/bin/env python3
import sys
if len(sys.argv) != 3:
    print("Uso: bin2hex32.py input.bin output.hex"); sys.exit(1)
data = open(sys.argv[1], "rb").read()
# padding a multipli di 4 byte
pad = (-len(data)) % 4
if pad: data += b"\x00" * pad
with open(sys.argv[2], "w") as f:
    for i in range(0, len(data), 4):
        b0, b1, b2, b3 = data[i:i+4]
        word = b0 | (b1<<8) | (b2<<16) | (b3<<24)   # little-endian
        f.write(f"{word:08x}\n")
