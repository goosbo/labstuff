module dflipflop(D,Clock,Resetn,Q);
input D,Clock,Resetn;
output reg Q;
always @(posedge Clock or posedge Resetn) 
begin
	if (Resetn) Q <= 1'b0;
	else Q <= D;
end
endmodule