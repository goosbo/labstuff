`include "tflipflop.v"

module binarysequence(Clk,Resetn,Q);
    input Clk,Resetn;
    output [2:0] Q;

    tflipflop tff0(~Q[0]|(Q[2]&Q[1]),Clk,Resetn,Q[0]);
    tflipflop tff1(Q[0],Clk,Resetn,Q[1]);
    tflipflop tff2(Q[1],Clk,Resetn,Q[2]);
endmodule
    