`include "dflipflop.v"

module ringcounter(Clk,Control,Q);

    input Clk;
    input [3:0] Control;
    output [3:0] Q;

    wire [3:0] D;
    dflipflop dff0(D[0],Clk,Control[0],1'b0,Q[0]);
    dflipflop dff1(D[1],Clk,Control[1],1'b0,Q[1]);
    dflipflop dff2(D[2],Clk,Control[2],1'b0,Q[2]);
    dflipflop dff3(D[3],Clk,1'b0,Control[3],Q[3]);

    assign D[0] = Q[1];
    assign D[1] = Q[2];
    assign D[2] = Q[3];
    assign D[3] = Q[0];

endmodule