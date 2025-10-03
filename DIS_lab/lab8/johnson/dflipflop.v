module dflipflop(D, Clock, Resetn, Q);
input D, Clock, Resetn;
output reg Q;

always @(negedge Clock or negedge Resetn) begin
    if (!Resetn)
        Q <= 0;
    else
        Q <= D;
end

endmodule
