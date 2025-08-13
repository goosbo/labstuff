`timescale 1ns/1ns
`include "gate2.v"

module gate2_tb();
reg a,b,c,d;
wire f;

gate2 g2(a,b,c,d,f);
initial
begin
	$dumpfile("gate2_tb.vcd");
	$dumpvars(0,gate2_tb);
	
	a=1'b0;b=1'b0;c=1'b0;d=1'b0;
	#15;
	
	a=1'b0;b=1'b0;c=1'b0;d=1'b1;
	#15;
	
	a=1'b0;b=1'b0;c=1'b1;d=1'b0;
	#15;
	
	a=1'b0;b=1'b0;c=1'b1;d=1'b1;
	#15;
	
	a=1'b0;b=1'b1;c=1'b0;d=1'b0;
	#15;
	
	a=1'b0;b=1'b1;c=1'b0;d=1'b1;
	#15;
	
	a=1'b0;b=1'b1;c=1'b1;d=1'b0;
	#15;
	
	a=1'b0;b=1'b1;c=1'b1;d=1'b1;
	#15;
	
	a=1'b1;b=1'b0;c=1'b0;d=1'b0;
	#15;
	
	a=1'b1;b=1'b0;c=1'b0;d=1'b1;
	#15;
	
	a=1'b1;b=1'b0;c=1'b1;d=1'b0;
	#15;
	
	a=1'b1;b=1'b0;c=1'b1;d=1'b1;
	#15;
	$display("test complete");
end
endmodule
