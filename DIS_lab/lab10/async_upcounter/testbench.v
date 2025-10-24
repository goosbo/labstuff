`include "async_upcounter.v"
`timescale 1ns/1ns

module testbench();
reg Clk, Resetn;
wire [3:0] Q;

async_upcounter auc(Clk,Resetn,Q);
initial begin
    $dumpfile("async_upcounter.vcd");
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