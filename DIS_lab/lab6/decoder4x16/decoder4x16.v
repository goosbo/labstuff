`include "decoder3x8.v"

module decoder4x16(w,en,y);
    input [3:0] w;
    input en;
    output [15:0] y;

    wire e1,e2;
    assign e1 = en&~w[3];
    assign e2 = en&w[3];

    decoder3x8 d1(w[2:0],e1,y[7:0]);
    decoder3x8 d2(w[2:0],e2,y[15:8]);
endmodule