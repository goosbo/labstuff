module tflipflop(T, Clock, Resetn, Q);
input T, Clock, Resetn;
output reg Q;
always @(negedge Clock or posedge Resetn)
begin
    if (Resetn) Q <= 1'b0;
    else if (T) Q <= ~Q;
end
endmodule