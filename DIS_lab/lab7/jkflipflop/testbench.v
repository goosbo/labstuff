`timescale 1ns/1ns
`include "jkflipflop.v"

module testbench();
reg J, K, Clock, Resetn;
wire Q;

jkflipflop FF(J, K, Clock, Resetn, Q);
initial begin
    $dumpfile("jkflipflop.vcd");
    $dumpvars(0,testbench);
    Clock = 0;
    forever #20 Clock = ~Clock;
end
initial begin
    Resetn = 1; 
    J = 1; K = 0;
    #10 Resetn = 0;  

    #40; J = 1; K = 0;
    #40; J = 0; K = 1;
    #40; J = 1; K = 1;
    #40; J = 0; K = 0;

    $display("test complete");
    #20 $finish;
end
endmodule

