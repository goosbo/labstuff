`timescale 1ns/1ns
`include "ringcounter.v"

module testbench();
reg Clk;
reg [3:0] Control;
wire [3:0] Q;

ringcounter rc(Clk,Control,Q);

initial begin
    $dumpfile("ringcounter.vcd");
    $dumpvars(0,testbench);

    Clk = 0;
    forever #10 Clk = ~Clk;
end
initial begin
    Control = 4'b1111; #20;
    Control = 4'b0000; #360;

    $display("test complete");
    #10 $finish;
end
endmodule   