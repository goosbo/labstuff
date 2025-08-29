`timescale 1ns/1ns
`include "mux4x1.v"

module testbench();
reg [3:0] w;
reg [1:0] s;
wire out;

mux4x1 m(w,s,out);
initial
begin
    $dumpfile("mux4x1.vcd");
    $dumpvars(0,testbench);

    w = 4'b1001; s=2'b00;
    #20;
    w = 4'b1001; s=2'b01;
    #20;
    w = 4'b1001; s=2'b10;
    #20;
    w = 4'b1001; s=2'b11;
    #20;

    $display("test complete");
end
endmodule