`timescale 1ns/1ps

module tb_mini_rv32i;
  reg         clk = 0;
  reg         rst = 1;
  reg  [31:0] io_in_a = 0;
  reg  [31:0] io_in_b = 0;
  reg  [1:0]  io_op   = 0;
  wire [31:0] io_out_res;
  wire        io_out_valid;
  wire [31:0] x3_out;
  wire        done;

  mini_rv32i dut (
    .clk(clk),
    .rst(rst),
    .io_in_a(io_in_a),
    .io_in_b(io_in_b),
    .io_op(io_op),
    .io_out_res(io_out_res),
    .io_out_valid(io_out_valid),
    .x3_out(x3_out),
    .done(done)
  );

  always #5 clk = ~clk; // clock a 100 MHz

  localparam integer NUM_TESTS  = 5;
  localparam integer MAX_CYCLES = 4096;

  // Tabelle di stimoli e risultati attesi
  reg [31:0] stim_a   [0:NUM_TESTS-1];
  reg [31:0] stim_b   [0:NUM_TESTS-1];
  reg [1:0]  stim_op  [0:NUM_TESTS-1];
  reg [31:0] expected [0:NUM_TESTS-1];

  integer test_id;
  reg     global_pass;

  // Task riutilizzabile che pilota il core, attende done e verifica gli output
  task run_test;
    input integer idx;
    input [31:0] a;
    input [31:0] b;
    input [1:0]  op;
    input [31:0] atteso;
    integer ciclo;
    reg test_ok;
    
    begin
      // Pre-carica gli ingressi MMIO e genera un reset pulito
      io_in_a = a;
      io_in_b = b;
      io_op   = op;

      rst = 1;
      repeat (4) @(posedge clk);
      rst = 0;

      test_ok = 0;

      begin : wait_done
        for (ciclo = 0; ciclo < MAX_CYCLES; ciclo = ciclo + 1) begin
          @(posedge clk);
          if (done) begin
            if (!io_out_valid) begin
              $display("[TEST %0d] ERRORE: io_out_valid non attivo", idx + 1);
              global_pass = 0;
            end

            if (io_out_res !== atteso) begin
              $display("[TEST %0d] ERRORE: io_out_res=0x%08x atteso=0x%08x",
                       idx + 1, io_out_res, atteso);
              global_pass = 0;
            end

            if (x3_out !== atteso) begin
              $display("[TEST %0d] ERRORE: x3_out=0x%08x atteso=0x%08x",
                       idx + 1, x3_out, atteso);
              global_pass = 0;
            end

            if (io_out_valid && io_out_res === atteso && x3_out === atteso) begin
              $display("[TEST %0d] OK: A=0x%08x B=0x%08x OP=%0d -> 0x%08x",
                       idx + 1, a, b, op, io_out_res);
              test_ok = 1;
            end

            disable wait_done; // esci dal ciclo appena done va alto
          end
        end
      end

      if (!test_ok) begin
        if (!done) begin
          $display("[TEST %0d] Timeout: segnale done mai attivo", idx + 1);
          global_pass = 0;
        end else begin
          $display("[TEST %0d] FALLITO", idx + 1);
        end
      end

      // Applica un reset breve per pulire lo stato prima del test successivo
      rst = 1;
      repeat (2) @(posedge clk);
      rst = 0;
      @(posedge clk);
    end
  endtask

  initial begin
    // Stimoli pensati per stressare le varie combinazioni del firmware
    stim_a[0]   = 32'd21;        stim_b[0]   = 32'd9;         stim_op[0]  = 2'd0; expected[0] = 32'd30;
    stim_a[1]   = 32'd9;         stim_b[1]   = 32'd21;        stim_op[1]  = 2'd1; expected[1] = 32'hFFFFFFF4;
    stim_a[2]   = 32'hFFFF0000;  stim_b[2]   = 32'h0000FFFF;  stim_op[2]  = 2'd0; expected[2] = 32'hFFFFFFFF;
    stim_a[3]   = 32'd5;         stim_b[3]   = 32'd7;         stim_op[3]  = 2'd2; expected[3] = 32'd12;
    stim_a[4]   = 32'h12345678;  stim_b[4]   = 32'h12345678;  stim_op[4]  = 2'd1; expected[4] = 32'd0;

    global_pass = 1;

    for (test_id = 0; test_id < NUM_TESTS; test_id = test_id + 1) begin
      run_test(test_id, stim_a[test_id], stim_b[test_id], stim_op[test_id], expected[test_id]);
    end

    if (global_pass) begin
      $display("\nTUTTI I TEST SONO PASSATI");
    end else begin
      $display("\nALCUNI TEST SONO FALLITI");
    end

    $finish;
  end

  initial begin
    $dumpfile("build/icarus_trace.vcd");
    $dumpvars(0, tb_mini_rv32i);
  end
endmodule
