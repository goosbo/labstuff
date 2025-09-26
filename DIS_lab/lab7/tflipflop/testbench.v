`timescale 1ns/1ns
`include "tflipflop.v"

module testbench();
reg T,Clock,Resetn;
wire Q;

tflipflop FF(T,Clock,Resetn,Q);
initial begin
    $dumpfile("tflipflop.vcd");
    $dumpvars(0,testbench);
    Clock = 0;
    forever #20 Clock = ~Clock;
end
initial begin
    Resetn = 0; 
    T = 1;
    #10 Resetn = 1;  

    #40; T = 1;
    #40; T = 0;
    #40; T = 1;
    #40; T = 0;
    #40; T = 1;
    #40; T = 0;

    $display("test complete");
    #20 $finish;
end
endmodule