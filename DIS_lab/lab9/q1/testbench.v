`include "q1.v"
`timescale 1ns/1ns

module testbench();
reg E, x,Clk, resetn;
wire A, B;
q1 q(E, x, Clk, resetn, A, B);

initial begin
    $dumpfile("q1.vcd");
    $dumpvars(0,testbench);

    Clk = 0;
    forever #10 Clk = ~Clk;
end
initial begin
    resetn = 0; #15;
    resetn = 1;
end
initial begin
    E = 1;x=1;#20;
    E = 0;x=1;#20;
    E = 1;x=1;#20;
    E = 0;x=1;#20;
    E = 1;x=1;#20;
    E = 0;x=1;#20;
    E = 1;x=0;#20;
    E = 0;x=1;#20;
    E = 1;x=0;#20;
    E = 0;x=1;#20;
    E = 1;x=0;#20;
    E = 0;x=1;#20;
    E = 1;x=0;#20;
    E = 0;x=1;#20;
    E = 1;x=0;#20;
    E = 0;x=1;#20;
    $display("test complete");
    #10 $finish;
end
endmodule
