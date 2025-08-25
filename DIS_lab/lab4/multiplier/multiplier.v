module multiplier(x,y,p);
    input [1:0] x,y;
    output [3:0] p;

    and(w1,x[0],y[0]);
    and(w2,x[0],y[1]);
    and(w3,x[1],y[0]);
    and(w4,x[1],y[1]);

    assign p[0] = w1;
    halfadder h1(w2,w3,p[1],c1);
    halfadder h2(w4,c1,p[2],p[3]);
endmodule

module halfadder(x,y,s,cout);
    input x,y;
    output s,cout;
    assign s = x^y;
    assign cout = x&y;
endmodule