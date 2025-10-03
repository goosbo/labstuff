
`include "dflipflop.v"
module johnson (clk, resetn, Q);
    input clk, resetn;
    output [4:0] Q;
    wire [4:0] D;

    assign D[0] = ~Q[4];
    assign D[4:1] = Q[3:0];

    dflipflop dff0 (D[0], clk, resetn, Q[0]);
    dflipflop dff1 (D[1], clk, resetn, Q[1]);
    dflipflop dff2 (D[2], clk, resetn, Q[2]);
    dflipflop dff3 (D[3], clk, resetn, Q[3]);
    dflipflop dff4 (D[4], clk, resetn, Q[4]);

endmodule
