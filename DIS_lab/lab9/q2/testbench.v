`include "q2.v"
`timescale 1ns/1ns

module testbench();
reg x, Clk, Resetn;
wire A, B;
q2 q(x, Clk, Resetn, A, B);

initial begin
    $dumpfile("q2.vcd");
    $dumpvars(0,testbench);

    Clk = 0;
    forever #10 Clk = ~Clk;
end
initial begin
    Resetn = 0; #15;
    Resetn = 1;
end
initial begin
    x=0;#80;
    x=1;#20;
    x=0;#20;
    x=1;#20;
    x=0;#20;
    x=1;#20;
    $display("test complete");
    #10 $finish;
end
endmodule
