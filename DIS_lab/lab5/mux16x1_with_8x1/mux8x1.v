module mux8x1(w,s,out);
    input [7:0] w;
    input [2:0] s;
    output reg out;

    always@(w or s)
    begin
        case (s)
            3'b000: out = w[0];
            3'b001: out = w[1];
            3'b010: out = w[2];
            3'b011: out = w[3];
            3'b100: out = w[4];
            3'b101: out = w[5];
            3'b110: out = w[6];
            3'b111: out = w[7];
        endcase
    end
endmodule