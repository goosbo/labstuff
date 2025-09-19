`timescale 1ns/1ns
`include "decoder3x8.v"

module testbench();
reg [2:0] w;
reg en;
wire [7:0]y;

decoder3x8 d(w,en,y);
initial
begin
	$dumpfile("decoder3x8.vcd");
	$dumpvars(0,testbench);
	
	en=1'b0;w=3'b000;
	#20;
	
	en=1'b0;w=3'b001;
	#20;
	
	en=1'b0;w=3'b010;
	#20;
	
	en=1'b0;w=3'b011;
	#20;
	
	en=1'b0;w=3'b100;
	#20;
	
	en=1'b0;w=3'b101;
	#20;
	
	en=1'b0;w=3'b110;
	#20;
	
	en=1'b0;w=3'b111;
	#20;
	
	en=1'b1;w=3'b000;
	#20;
	
	en=1'b1;w=3'b001;
	#20;
	
	en=1'b1;w=3'b010;
	#20;
	
	en=1'b1;w=3'b011;
	#20;
	
	en=1'b1;w=3'b100;
	#20;
	
	en=1'b1;w=3'b101;
	#20;
	
	en=1'b1;w=3'b110;
	#20;
	
	en=1'b1;w=3'b111;
	#20;
	
	$display("test complete");
end
endmodule
