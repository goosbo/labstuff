module mux2x1(w,s,out);
    input [1:0] w;
    input s;
    output reg out;

    always@(w or s)
    begin
        case (s)
            1'b0:out = w[0];
            1'b1:out = w[1]; 
        endcase
    end
endmodule