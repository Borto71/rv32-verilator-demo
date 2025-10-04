module mini_rv32i (
  input  wire        clk, // clock 
  input  wire        rst, // reset

  // --- MMIO "host" ---
  input  wire [31:0] io_in_a, // operandi a 32 bit forniti dal testbench
  input  wire [31:0] io_in_b, // operandi a 32 bit forniti dal testbench
  input  wire [1:0]  io_op,        // 0=ADD, 1=SUB
  output reg  [31:0] io_out_res, // registro a 32 bit di output verso il testbench
  output reg         io_out_valid, // quando risultato pronto si alza a 1

  // Debug/term
  output reg  [31:0] x3_out, // valore del registro x3 (per debug), esporta verso fuori un registro a 32 bit 
  output reg         done // segnala al testbench che il programma è terminato, mettendo a 1 questo segnale
);
  // ------------------ Stato CPU ------------------
  reg [31:0] x[0:31]; // array di 32 registri a 32 bit
  reg [31:0] pc; // program counter

  // ROM istruzioni (1 KiB)
  reg [31:0] imem [0:255]; // array di 256 parole a 32 bit
  initial begin
    $readmemh("firmware/prog.hex", imem); // prima dell'inizio della simulazione, carica il contenuto della ROM dal file hex
  end
  wire [31:0] instr  = imem[pc[9:2]]; // fa il fetch dell'istruzione 

  // Decodifica
  wire [6:0]  opcode = instr[6:0]; // tipo di istruzione, LOAD, STORE, OP-IMM, OP, BRANCH, LUI, SYSTEM
  wire [2:0]  funct3 = instr[14:12]; // sottotipo di istruzione, es. ADD/SUB per OP
  wire [6:0]  funct7 = instr[31:25]; // ulteriore sottotipo di istruzione, es. ADD/SUB per OP
  wire [4:0]  rs1    = instr[19:15]; // sorgente 1
  wire [4:0]  rs2    = instr[24:20]; // sorgente 2
  wire [4:0]  rd     = instr[11:7]; // destinazione

  wire [31:0] imm_i = {{20{instr[31]}}, instr[31:20]}; // immediato con sign in gia pronto. replica bit di segno 20 volte
  wire [31:0] imm_s = {{20{instr[31]}}, instr[31:25], instr[11:7]}; // immediato con sign in gia pronto, replica bit di segno 20 volte
  wire [31:0] imm_u = {instr[31:12], 12'b0}; // 20 bit alti vanno nelle posizioni [31:12], con 12 zeri in coda
  wire [31:0] imm_b = {{19{instr[31]}}, instr[31], instr[7], // offset a 13 bit rimescolato secondo lo standard
                       instr[30:25], instr[11:8], 1'b0};

  // DMEM (1 KiB) @ 0x0000_0000..0x0000_03FF
  reg [31:0] dmem [0:255]; // array di 256 parole a 32 bit

  // ----------- MMIO indirizzi completi -----------
  localparam [31:0] MMIO_BASE = 32'h8000_0000; // base periferica MMIO 
  localparam [31:0] MMIO_A    = MMIO_BASE + 32'h0; // offset 0
  localparam [31:0] MMIO_B    = MMIO_BASE + 32'h4; // offset 4
  localparam [31:0] MMIO_OP   = MMIO_BASE + 32'h8; // offset 8
  localparam [31:0] MMIO_RES  = MMIO_BASE + 32'hC; // 

  // Letture MMIO (match su indirizzo completo)
  function [31:0] mmio_read;
    input [31:0] addr;
    begin
      case (addr)
        MMIO_A:  mmio_read = io_in_a;
        MMIO_B:  mmio_read = io_in_b;
        MMIO_OP: mmio_read = {30'b0, io_op};
        default: mmio_read = 32'h0;
      endcase
    end
  endfunction

  // Scritture MMIO (match su indirizzo completo)
  task mmio_write;
    input [31:0] addr;
    input [31:0] wdata;
    begin
      if (addr == MMIO_RES) begin
        io_out_res   <= wdata;
        io_out_valid <= 1'b1;
      end
    end
  endtask

  // ----------- Calcoli combinazionali utili -----------
  wire [31:0] addr_i = x[rs1] + imm_i; // indirizzo per LW
  wire [31:0] addr_s = x[rs1] + imm_s; // indirizzo per SW

  integer i;
  always @(posedge clk) begin
    if (rst) begin
      pc           <= 0;
      done         <= 0;
      x3_out       <= 0;
      io_out_res   <= 0;
      io_out_valid <= 0;
      for (i=0;i<32;i=i+1) x[i] <= 0;
    end else if (!done) begin
      // opzionale: clear dell'output-valid se vuoi un impulso di 1 ciclo
      // io_out_valid <= 1'b0;

      case (opcode)
        7'h37: begin // LUI
          if (rd!=0) x[rd] <= imm_u;
          pc <= pc + 4;
        end
        7'h13: begin // OP-IMM (ADDI)
          if (funct3 == 3'b000) begin
            if (rd!=0) x[rd] <= x[rs1] + imm_i;
          end
          pc <= pc + 4;
        end
        7'h33: begin // OP (ADD/SUB)
          if (funct3 == 3'b000 && funct7 == 7'b0000000) begin // ADD
            if (rd!=0) x[rd] <= x[rs1] + x[rs2];
          end else
          if (funct3 == 3'b000 && funct7 == 7'b0100000) begin // SUB
            if (rd!=0) x[rd] <= x[rs1] - x[rs2];
          end
          pc <= pc + 4;
        end
        7'h03: begin // LOAD (LW)
          if (funct3 == 3'b010) begin
            if (addr_i[31:28] == 4'h8) begin
              if (rd!=0) x[rd] <= mmio_read(addr_i);
            end else begin
              if (rd!=0) x[rd] <= dmem[addr_i[9:2]];
            end
          end
          pc <= pc + 4;
        end
        7'h23: begin // STORE (SW)
          if (funct3 == 3'b010) begin
            if (addr_s[31:28] == 4'h8) begin
              mmio_write(addr_s, x[rs2]);
            end else begin
              dmem[addr_s[9:2]] <= x[rs2];
            end
          end
          pc <= pc + 4;
        end
        7'h63: begin // BRANCH (BEQ)
          if (funct3 == 3'b000) begin
            pc <= (x[rs1] == x[rs2]) ? (pc + imm_b) : (pc + 4);
          end else begin
            pc <= pc + 4; // altre branch non implementate
          end
        end
        7'h73: begin // SYSTEM (EBREAK imm=1)
          if (instr[31:20] == 12'h001) begin
            done   <= 1;
            x3_out <= x[3];
          end
          pc <= pc + 4;
        end
        default: begin
          pc <= pc + 4; // NOP
        end
      endcase

      x[0] <= 32'b0; // x0 sempre zero
    end
  end
endmodule
