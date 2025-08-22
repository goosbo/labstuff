`timescale 1ns/1ns
`include "q4.v"

module testbench();
reg a,b,c,d;
wire f;

q4 q(a,b,c,d,f);
initial
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,testbench);
	
	a=1'b0;b=1'b0;c=1'b0;d=1'b0;
	#20;
	
	a=1'b0;b=1'b0;c=1'b0;d=1'b1;
	#20;
	
	a=1'b0;b=1'b0;c=1'b1;d=1'b0;
	#20;
	
	a=1'b0;b=1'b0;c=1'b1;d=1'b1;
	#20;
	
	a=1'b0;b=1'b1;c=1'b0;d=1'b0;
	#20;
	
	a=1'b0;b=1'b1;c=1'b0;d=1'b1;
	#20;
	
	a=1'b0;b=1'b1;c=1'b1;d=1'b0;
	#20;
	
	a=1'b0;b=1'b1;c=1'b1;d=1'b1;
	#20;
	
	a=1'b1;b=1'b0;c=1'b0;d=1'b0;
	#20;
	
	a=1'b1;b=1'b0;c=1'b0;d=1'b1;
	#20;
	
	a=1'b1;b=1'b0;c=1'b1;d=1'b0;
	#20;
	
	a=1'b1;b=1'b0;c=1'b1;d=1'b1;
	#20;
	
	a=1'b1;b=1'b1;c=1'b0;d=1'b0;
	#20;
	
	a=1'b1;b=1'b1;c=1'b0;d=1'b1;
	#20;
	
	a=1'b1;b=1'b1;c=1'b1;d=1'b0;
	#20;
	
	a=1'b1;b=1'b1;c=1'b1;d=1'b1;
	#20;
	
	$display("test complete");
end
endmodule
