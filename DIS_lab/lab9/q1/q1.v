`include "jkflipflop.v"

module q1(E,x,Clk,resetn,A,B);
    wire Ja, Ka, Jb, Kb;
    input E, x, Clk, resetn;
    output A, B;

    assign Ja = B & E & x | ~B & E & ~x;
    assign Ka = B & E & x | ~B & E & ~x;
    assign Jb = E;
    assign Kb = E;
    jkflipflop jk1(Ja, Ka, Clk, resetn, A);
    jkflipflop jk2(Jb, Kb, Clk, resetn, B);
endmodule