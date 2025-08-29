module comparator4bit(x,y,eq,lt,gt);
    input [3:0] x,y;
    output eq,lt,gt;
    reg eq,lt,gt;
    always @(x or y)
    begin
        eq = (x==y) ? 1'b1 : 1'b0;
        gt = (x>y) ? 1'b1 : 1'b0;
        lt = ~gt & ~eq;
    end
endmodule
