`timescale 1ns/1ps

module tb_mini_rv32i;
  reg         clk = 0;
  reg         rst = 1;
  reg  [31:0] io_in_a = 21;
  reg  [31:0] io_in_b = 9;
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

  always #5 clk = ~clk;

  initial begin
    repeat (4) @(posedge clk);
    rst = 0;
    repeat (2000) begin
      @(posedge clk);
      if (done) begin
        $display("Program finished. x3 = %0d (0x%08x)", x3_out, x3_out);
        if (io_out_valid)
          $display("MMIO result = %0d (0x%08x)", io_out_res, io_out_res);
        else
          $display("MMIO result not written.");
        $finish;
      end
    end
    $display("Timeout: 'done' never asserted.");
    $finish;
  end

  initial begin
    $dumpfile("build/icarus_trace.vcd");
    $dumpvars(0, tb_mini_rv32i);
  end
endmodule
