`include "dflipflop.v"
module shiftregister(I, CLK, Q);
    input I, CLK;
    output [5:0] Q;
    wire [5:0] dff_out;

    dflipflop dff0 (I, CLK, dff_out[0]);
    dflipflop dff1 (dff_out[0], CLK, dff_out[1]);
    dflipflop dff2 (dff_out[1], CLK, dff_out[2]);
    dflipflop dff3 (dff_out[2], CLK, dff_out[3]);
    dflipflop dff4 (dff_out[3], CLK, dff_out[4]);
    dflipflop dff5 (dff_out[4], CLK, dff_out[5]);

    assign Q = dff_out;
endmodule