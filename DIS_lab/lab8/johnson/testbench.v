`include "johnson.v"
`timescale 1ns/1ns

module testbench();
reg clk;
reg resetn;
wire [4:0] Q;

johnson jc(clk, resetn, Q);

initial begin
    $dumpfile("johnson.vcd");
    $dumpvars(0, testbench);
    clk = 0;
    resetn = 0;
    #15 resetn = 1;
    #200 $finish;
end

always #10 clk = ~clk;

initial begin
    $display("test complete");
end
endmodule
