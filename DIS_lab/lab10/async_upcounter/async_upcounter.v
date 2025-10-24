`include "tflipflop.v"

module async_upcounter(Clk,Resetn,Q);
    input Clk,Resetn;
    output [3:0] Q;

    tflipflop tff0 (1'b1, Clk, Resetn, Q[0]);
    tflipflop tff1 (1'b1, Q[0], Resetn, Q[1]);
    tflipflop tff2 (1'b1, Q[1], Resetn, Q[2]);
    tflipflop tff3 (1'b1, Q[2], Resetn, Q[3]);
endmodule


