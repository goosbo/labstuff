module mux2x1(w,s,out);
    input [1:0] w;
    input s;
    output out;
    reg out;
    always @(w or s)
    begin
        if (s == 1'b1)
            out = w[1];
        else
            out = w[0];
    end
endmodule