module decoder2x4(w,en,y);
    input [1:0] w;
    input en;
    output reg [3:0] y;

    always @(w or en)
    begin
        case(en)
        1'b0: y = 4'b1111;
        1'b1:
        begin
            case(w)
            2'b00: y = 4'b1110;
            2'b01: y = 4'b1101;
            2'b10: y = 4'b1011;
            2'b11: y = 4'b0111;
            endcase
        end
        endcase
    end
endmodule