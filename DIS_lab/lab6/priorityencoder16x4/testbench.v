`timescale 1ns/1ns
`include "priorityencoder16x4.v"

module testbench();
reg [15:0] w;
wire [3:0]y;
wire z;
priorityencoder16x4 e(w,y,z);
initial
begin
	$dumpfile("priorityencoder16x4.vcd");
	$dumpvars(0,testbench);
	
	w=16'b1111111111111111;
	#20;
	
	w=16'b0000000000000000;
	#20;
	
	w=16'b0001110101010101;
	#20;
	
	w=16'b0011101010101011;
	#20;
	
	w=16'b0000000010101011;
	#20;
	
	w=16'b0000010010101011;
	#20;
	
	w=16'b0000000000000001;
	#20;
	
	w=16'b0000000000001011;
	#20;

	$display("test complete");
end
endmodule
