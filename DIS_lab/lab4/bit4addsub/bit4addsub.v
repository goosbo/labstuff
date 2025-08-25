module bit4addsub(control, x, y, s, cout);
    input control;
    input [3:0] x, y;
    output [3:0] s;
    output cout;

    wire [3:0] y_xor;
    assign y_xor = y ^ {4{control}};

    wire c0, c1, c2;

    fulladder fa0(control, x[0], y_xor[0], s[0], c0);
    fulladder fa1(c0, x[1], y_xor[1], s[1], c1);
    fulladder fa2(c1, x[2], y_xor[2], s[2], c2);
    fulladder fa3(c2, x[3], y_xor[3], s[3], cout);
endmodule

module fulladder(cin,x,y,s,cout);
    input cin,x,y;
    output s,cout;
    assign s = x^y^cin;
    assign cout = (x&y)|(y&cin)|(cin&x);
endmodule 