#!/usr/bin/env python3
"""Converti un file binario in parole esadecimali a 32 bit (formato little-endian).

Il firmware del core viene salvato come blocco binario grezzo: ogni 4 byte
costituiscono una word a 32 bit in ordine little-endian. Questo script legge il
file binario, aggiunge eventuale padding finale (zero) per completare l'ultima
word e scrive il file di testo con una word esadecimale (8 cifre) per riga.
"""

from pathlib import Path
import sys


def print_usage() -> None:
    """Mostra un breve messaggio d'uso in italiano."""

    print("Uso: bin2hex32.py input.bin output.hex")


def read_binary(path: Path) -> bytes:
    """Legge il file binario e restituisce i byte grezzi."""

    try:
        return path.read_bytes()
    except FileNotFoundError:
        sys.exit(f"Errore: file di input '{path}' non trovato")


def pad_to_word(data: bytes, word_size: int = 4) -> bytes:
    """Applica padding con zeri per raggiungere un multiplo di word_size."""

    missing = (-len(data)) % word_size
    if missing:
        data += b"\x00" * missing
    return data


def words_from_bytes(data: bytes) -> list[int]:
    """Traduce il flusso di byte in una lista di word a 32 bit."""

    words = []
    for index in range(0, len(data), 4):
        b0, b1, b2, b3 = data[index:index + 4]
        word = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24)
        words.append(word)
    return words


def write_hex_words(words: list[int], output_path: Path) -> None:
    """Scrive ogni word a 32 bit come riga esadecimale (otto cifre)."""

    with output_path.open("w", encoding="ascii") as destination:
        for word in words:
            destination.write(f"{word:08x}\n")


def main(argv: list[str]) -> int:
    if len(argv) != 3:
        print_usage()
        return 1

    input_path = Path(argv[1])
    output_path = Path(argv[2])

    raw_bytes = read_binary(input_path)
    padded_bytes = pad_to_word(raw_bytes)
    word_list = words_from_bytes(padded_bytes)
    write_hex_words(word_list, output_path)

    return 0


if __name__ == "__main__":  # punto di ingresso esplicito
    sys.exit(main(sys.argv))
