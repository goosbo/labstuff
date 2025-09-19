`timescale 1ns/1ns
`include "priorityencoder4x2.v"

module testbench();
reg [3:0] w;
wire [1:0]y;
wire z;
priorityencoder4x2 e(w,y,z);
initial
begin
	$dumpfile("priorityencoder4x2.vcd");
	$dumpvars(0,testbench);
	
	w=4'b0000;
	#20;
	
	w=4'b0001;
	#20;
	
	w=4'b0010;
	#20;
	
	w=4'b0011;
	#20;
	
	w=4'b0100;
	#20;
	
	w=4'b0101;
	#20;
	
	w=4'b0110;
	#20;
	
	w=4'b0111;
	#20;

    w=4'b1000;
	#20;
	
	w=4'b1001;
	#20;
	
	w=4'b1010;
	#20;
	
	w=4'b1011;
	#20;
	
	w=4'b1100;
	#20;
	
	w=4'b1101;
	#20;
	
	w=4'b1110;
	#20;
	
	w=4'b1111;
	#20;
	
	$display("test complete");
end
endmodule
