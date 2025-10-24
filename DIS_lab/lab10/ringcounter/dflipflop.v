module dflipflop(D,Clock,Resetn,Presetn,Q);
input D,Clock,Resetn,Presetn;
output reg Q;
always @(negedge Clock or posedge Resetn or posedge Presetn) 
begin
	if (Resetn) Q <= 1'b0;
	else if (Presetn) Q <= 1'b1;
	else Q <= D;
end
endmodule