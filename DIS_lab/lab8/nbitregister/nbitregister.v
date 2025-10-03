module nbitregister #(parameter N=4) (clk,D,Q);
    input clk;
    input [N-1:0] D;
    output reg [N-1:0] Q;

    always @(negedge clk) begin
        Q <= D;
    end
endmodule