module tflipflop(T, Clk, Resetn, Q);
input T, Clk, Resetn;
output reg Q;
always @(negedge Clk or negedge Resetn)
begin
    if (!Resetn) Q <= 1'b0;
    else if (T) Q <= ~Q;
end
endmodule