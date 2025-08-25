module bcdadder(x,y,s,cout);
    input [3:0] x,y;
    output [3:0] s;
    output cout;

    wire [3:0] sum1;
    wire c1;
    wire [3:0] sum2;
    wire c2;
    wire add6;

    bit4add add1(1'b0, x, y, sum1, c1);

    assign add6 = (sum1 > 4'b1001) || c1;
    bit4add add2(1'b0, sum1, 4'b0110, sum2, c2);

    assign s = add6 ? sum2 : sum1;
    assign cout = add6 ? c2|c1 : 1'b0;
endmodule

module bit4add(cin, x, y, s, cout);
    input cin;
    input [3:0] x, y;
    output [3:0] s;
    output cout;

    fulladder fa0(cin, x[0], y[0], s[0], c0);
    fulladder fa1(c0, x[1], y[1], s[1], c1);
    fulladder fa2(c1, x[2], y[2], s[2], c2);
    fulladder fa3(c2, x[3], y[3], s[3], cout);
endmodule

module fulladder(cin,x,y,s,cout);
    input cin,x,y;
    output s,cout;
    assign s = x^y^cin;
    assign cout = (x&y)|(y&cin)|(cin&x);
endmodule 