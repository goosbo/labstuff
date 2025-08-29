`include "mux2x1.v"
`include "mux8x1.v"

module mux16x1(w,s,out);
    input [15:0] w;
    input [3:0] s;
    output out;
    wire m0out,m1out;

    mux8x1 m0(w[7:0],s[2:0],m0out);
    mux8x1 m1(w[15:8],s[2:0],m1out);
    mux2x1 m2({m1out,m0out},s[3],out);
endmodule