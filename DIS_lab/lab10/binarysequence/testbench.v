`include "binarysequence.v"
`timescale 1ns/1ns

module testbench();
reg Clk,Resetn;
wire [2:0] Q;

binarysequence b(Clk,Resetn,Q);

initial begin
    $dumpfile("binarysequence.vcd");
    $dumpvars(0,testbench);

    Clk = 0;
    forever #10 Clk = ~Clk;
end
initial begin
    Resetn = 1; #20;
    Resetn = 0; #720;

    $display("test complete");
    #10 $finish;
end
endmodule