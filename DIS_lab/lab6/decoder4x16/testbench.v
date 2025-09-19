`timescale 1ns/1ns
`include "decoder4x16.v"

module testbench();
reg [3:0] w;
reg en;
wire [15:0]y;

decoder4x16 d(w,en,y);
initial
begin
	$dumpfile("decoder4x16.vcd");
	$dumpvars(0,testbench);
	
	en=1'b0;w=4'b0000;
	#5;
	
	en=1'b0;w=4'b0001;
	#5;
	
	en=1'b0;w=4'b0010;
	#5;
	
	en=1'b0;w=4'b0011;
	#5;
	
	en=1'b0;w=4'b0100;
	#5;
	
	en=1'b0;w=4'b0101;
	#5;
	
	en=1'b0;w=4'b0110;
	#5;
	
	en=1'b0;w=4'b0111;
	#5;

    en=1'b0;w=4'b1000;
	#5;
	
	en=1'b0;w=4'b1001;
	#5;
	
	en=1'b0;w=4'b1010;
	#5;
	
	en=1'b0;w=4'b1011;
	#5;
	
	en=1'b0;w=4'b1100;
	#5;
	
	en=1'b0;w=4'b1101;
	#5;
	
	en=1'b0;w=4'b1110;
	#5;
	
	en=1'b0;w=4'b1111;
	#5;
	
	en=1'b1;w=4'b0000;
	#5;
	
	en=1'b1;w=4'b0001;
	#5;
	
	en=1'b1;w=4'b0010;
	#5;
	
	en=1'b1;w=4'b0011;
	#5;
	
	en=1'b1;w=4'b0100;
	#5;
	
	en=1'b1;w=4'b0101;
	#5;
	
	en=1'b1;w=4'b0110;
	#5;
	
	en=1'b1;w=4'b0111;
	#5;

    en=1'b1;w=4'b1000;
	#5;
	
	en=1'b1;w=4'b1001;
	#5;
	
	en=1'b1;w=4'b1010;
	#5;
	
	en=1'b1;w=4'b1011;
	#5;
	
	en=1'b1;w=4'b1100;
	#5;
	
	en=1'b1;w=4'b1101;
	#5;
	
	en=1'b1;w=4'b1110;
	#5;
	
	en=1'b1;w=4'b1111;
	#5;
	
	
	$display("test complete");
end
endmodule
