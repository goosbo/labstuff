`include "shiftregister.v"
`timescale 1ns/1ns

module testbench();
reg I, CLK;
wire [5:0] Q;

shiftregister sr(I, CLK, Q);
initial
begin
    $dumpfile("shiftregister.vcd");
    $dumpvars(0,testbench);
    CLK = 0;
    forever #10 CLK = ~CLK;
end

initial
begin
    I = 1;
    #20;
    I = 0;
    #20;
    I = 1;
    #20;
    I = 1;
    #20;
    I = 0;
    #20;
    I = 1;
    #20;
    I = 0;
    #20;
    I = 1;
    #20;
    I = 1;
    #20;
    I = 0;
    #20;
    I = 1;
    #20;
    I = 0;
    #20 $finish;
    $display("test complete");
    
end
endmodule