`include "dflipflop.v"
module shiftregister(I, CLK, Q);
    input I, CLK;
    output [5:0] Q;
    wire [5:0] D;

    dflipflop dff0 (I, CLK, D[0]);
    dflipflop dff1 (D[0], CLK, D[1]);
    dflipflop dff2 (D[1], CLK, D[2]);
    dflipflop dff3 (D[2], CLK, D[3]);
    dflipflop dff4 (D[3], CLK, D[4]);
    dflipflop dff5 (D[4], CLK, D[5]);

    assign Q = D;
endmodule