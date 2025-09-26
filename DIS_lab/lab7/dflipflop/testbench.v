`timescale 1ns/1ns
`include "dflipflop.v"

module testbench();
reg D,Clock,Resetn;
wire Q;

dflipflop FF(D,Clock,Resetn,Q);
initial begin
    $dumpfile("dflipflop.vcd");
    $dumpvars(0,testbench);
    Clock = 0;
    forever #20 Clock = ~Clock;
end
initial begin
    D = 1; Resetn = 0;
    #20;
    D = 1; Resetn = 0;
    #20;
    D = 0; Resetn = 0;
    #20;
    D = 1; Resetn = 1;
    #20;
    $display("test complete");
    #20 $finish;
end
endmodule