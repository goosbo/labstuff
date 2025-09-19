module decoder3x8(w,en,y);
    input [2:0] w;
    input en;
    output reg [7:0] y;
    integer k;

    always @(w or en)
    begin
        for(k = 0; k < 8; k = k+1)
        if((w == k) && (en == 1))
        y[k] = 1;
        else
        y[k] = 0;
    end
endmodule