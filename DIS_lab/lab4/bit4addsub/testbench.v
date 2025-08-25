`timescale 1ns/1ns
`include "bit4addsub.v"

module testbench();
reg control;
reg [3:0] x,y;
wire [3:0] s;
wire cout;
bit4addsub b(control, x, y, s, cout);
initial
begin
	$dumpfile("bit4addsub.vcd");
	$dumpvars(0,testbench);
	
	control=1'b0; x=4'b1110; y=4'b1001;
	#20;

	control=1'b0; x=4'b0011; y=4'b0101;
	#20;

	control=1'b1; x=4'b1110; y=4'b1001;
	#20;

	control=1'b1; x=4'b0011; y=4'b0101;
	#20;
	
	$display("test complete");
end
endmodule
