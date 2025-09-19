module priorityencoder16x4(w,y,z);
    input [15:0] w;
    output reg[3:0] y;
    output z;
    integer k;
    assign z = |w;
    always @(w)
    begin
        y = 2'bxx;
        for(k = 0; k < 16; k = k+1)
        if(w[k] == 1)y = k;
    end
endmodule