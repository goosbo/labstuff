module mux4x1(w,s,out);
    input [3:0] w;
    input [1:0] s;
    output reg out;

    always@(w or s)
    out = s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
endmodule