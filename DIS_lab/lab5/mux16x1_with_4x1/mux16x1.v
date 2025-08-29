`include "mux4x1.v"

module mux16x1(w,s,out);
    input [15:0] w;
    input [3:0] s;
    output out;
    wire m0out,m1out,m2out,m3out;

    mux4x1 m0(w[3:0],s[1:0],m0out);
    mux4x1 m1(w[7:4],s[1:0],m1out);
    mux4x1 m2(w[11:8],s[1:0],m2out);
    mux4x1 m3(w[15:12],s[1:0],m3out);
    mux4x1 m4({m3out,m2out,m1out,m0out},s[3:2],out);
endmodule