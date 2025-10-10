module jkflipflop(J, K, Clk,resetn, Q);
    input J, K, Clk, resetn;
    output reg Q;
    always @(negedge Clk or negedge resetn)
    begin
        if (!resetn) Q <= 1'b0;
        else if (J && !K) Q <= 1'b1;
        else if (!J && K) Q <= 1'b0;
        else if (J && K) Q <= ~Q;
    end
endmodule