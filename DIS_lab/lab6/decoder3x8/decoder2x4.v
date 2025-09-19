module decoder2x4(w,en,y);
    input [1:0] w;
    input en;
    output reg [3:0] y;

    always @(w or en)
    begin
        if(en == 1'b0)
        y = 4'b0000;
        else
        begin
            if(w == 2'b00) y = 4'b0001;
            else if(w == 2'b01) y = 4'b0010;
            else if(w == 2'b10) y = 4'b0100;
            else y = 4'b1000;
        end
    end
endmodule