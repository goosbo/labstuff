`timescale 1ns/1ns
`include "comparator4bit.v"

module testbench();
reg [3:0] x,y;
wire eq,lt,gt;

comparator4bit c(x,y,eq,lt,gt);
initial
begin
	$dumpfile("comparator4bit.vcd");
	$dumpvars(0,testbench);
	
    x = 4'b1101;y=4'b1101;
    #20;

    x = 4'b0101;y=4'b1001;
    #20;  

    x = 4'b1000;y=4'b0111;
    #20;
	
	$display("test complete");
end
endmodule
