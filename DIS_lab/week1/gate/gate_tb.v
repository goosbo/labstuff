`timescale 1ns/1ns
`include "gate.v"

module gate_tb();
reg a,b,c;
wire f;

gate g1(a,b,c,f);
initial
begin
	$dumpfile("gate_tb.vcd");
	$dumpvars(0,gate_tb);
	
	a=1'b0;b=1'b0;c=1'b0;
	#20;
	
	a=1'b0;b=1'b0;c=1'b1;
	#20;
	
	a=1'b0;b=1'b1;c=1'b0;
	#20;
	
	a=1'b0;b=1'b1;c=1'b1;
	#20;
	
	a=1'b1;b=1'b0;c=1'b0;
	#20;
	
	a=1'b1;b=1'b0;c=1'b1;
	#20;
	
	a=1'b1;b=1'b1;c=1'b0;
	#20;
	
	a=1'b1;b=1'b1;c=1'b1;
	#20;
	
	$display("test complete");
end
endmodule
