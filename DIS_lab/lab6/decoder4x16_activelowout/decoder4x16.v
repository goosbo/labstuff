`include "decoder2x4.v"

module decoder4x16(w,en,y);
    input [3:0] w;
    input en;
    output [15:0] y;

    wire [3:0] e;
    decoder2x4 d0(w[3:2],en,e);
    decoder2x4 d1(w[1:0],~e[0],y[3:0]);
    decoder2x4 d2(w[1:0],~e[1],y[7:4]);
    decoder2x4 d3(w[1:0],~e[2],y[11:8]);
    decoder2x4 d4(w[1:0],~e[3],y[15:12]);
endmodule