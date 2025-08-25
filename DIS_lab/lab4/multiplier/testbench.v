`timescale 1ns/1ns
`include "multiplier.v"

module testbench();
reg [1:0] x,y;
wire [3:0] p;

multiplier m(x,y,p);
initial
begin
	$dumpfile("multiplier.vcd");
	$dumpvars(0,testbench);
	
	x=2'b11; y=2'b11;
	#20;

	x=2'b10; y=2'b11;
	#20;

	x=2'b01; y=2'b00;
	#20;

	x=2'b10; y=2'b10;
	#20;
	
	$display("test complete");
end
endmodule
