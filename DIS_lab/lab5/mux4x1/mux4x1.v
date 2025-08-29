`include "mux2x1.v"

module mux4x1(w, s, out);
    input [3:0] w;
    input [1:0] s;
    output out;
    wire m1out, m2out;
    mux2x1 m1(w[1:0], s[0], m1out);
    mux2x1 m2(w[3:2], s[0], m2out);
    mux2x1 m3({m2out, m1out}, s[1], out);
endmodule