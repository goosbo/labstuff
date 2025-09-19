`include "decoder2x4.v"

module decoder3x8(w,en,y);
    input [2:0] w;
    input en;
    output [7:0] y;

    wire e1,e2;
    assign e1 = en&~w[2];
    assign e2 = en&w[2];

    decoder2x4 d1(w[1:0],e1,y[3:0]);
    decoder2x4 d2(w[1:0],e2,y[7:4]);
endmodule