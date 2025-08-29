`timescale 1ns/1ns
`include "bcdadder.v"

module testbench();

reg [3:0] x,y;
reg cin;
wire [3:0] s;
wire cout;

bcdadder b(x, y,cin, s, cout);
initial
begin
	$dumpfile("bcdadder.vcd");
	$dumpvars(0,testbench);
	
	x=4'b1000; y=4'b1000;cin=1'b0;
	#20;

	x=4'b0011; y=4'b0101;cin=1'b0;
	#20;

	x=4'b0100; y=4'b1000;cin=1'b1;
	#20;

	x=4'b0011; y=4'b1001;cin=1'b1;
	#20;
	
	$display("test complete");
end
endmodule
