`timescale 1ns/1ns
`include "adder.v"

module testbench();
reg x,y,cin;
wire s,cout;

fulladder f(cin,x,y,s,cout);
initial
begin
	$dumpfile("fulladd.vcd");
	$dumpvars(0,testbench);
	
	x=1'b0;y=1'b0;cin=1'b0;
	#20;

    x=1'b0;y=1'b0;cin=1'b1;
	#20;
	
	x=1'b0;y=1'b1;cin=1'b0;
	#20;

    x=1'b0;y=1'b1;cin=1'b1;
	#20;
	
	x=1'b1;y=1'b0;cin=1'b0;
	#20;

	x=1'b1;y=1'b0;cin=1'b1;
	#20;
	
	x=1'b1;y=1'b1;cin=1'b0;
	#20;

	x=1'b1;y=1'b1;cin=1'b1;
	#20;
	
	$display("test complete");
end
endmodule
