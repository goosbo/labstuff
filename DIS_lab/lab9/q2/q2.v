`include "tflipflop.v"

module q2(x,Clk,Resetn,A,B);
    wire Ta, Tb;
    input x, Clk, Resetn;
    output A, B;
    assign Ta =  ~A&B|B&~x;
    assign Tb = ~B&~x | A&~x | ~A&B&x;
    tflipflop tff1(Ta, Clk, Resetn, A);
    tflipflop tff2(Tb, Clk, Resetn, B);
endmodule