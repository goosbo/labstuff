`timescale 1ns/1ns
`include "nbitregister.v"

module testbench();
    reg [3:0] D;
    reg clk;
    wire [3:0] Q;

    nbitregister #(4) reg4(clk, D, Q);

    initial begin
        $dumpfile("nbitregister.vcd");
        $dumpvars(0, testbench);
        clk = 0;
        forever #10 clk = ~clk;
    end

    initial begin
        D = 4'b1010; #20;
        D = 4'b1100; #20;
        D = 4'b1111; #20;
        D = 4'b0000; #20;
        D = 4'b0110; #20;
        $display("test complete");
        $finish;
    end
endmodule