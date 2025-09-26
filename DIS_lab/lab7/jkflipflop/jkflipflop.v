module jkflipflop(J, K, Clock, Resetn, Q);
input J, K, Clock, Resetn;
output reg Q;
always @(posedge Clock)
begin
    if (Resetn) Q <= 1'b0;
    else if (J && !K) Q <= 1'b1;
    else if (!J && K) Q <= 1'b0;
    else if (J && K) Q <= ~Q;
end
endmodule