module halfadder(x,y,s,cout);
    input x,y;
    output s,cout;
    assign s = x^y;
    assign cout = x&y;
endmodule

module fulladder(cin,x,y,s,cout);
    input cin,x,y;
    output s,cout;
    assign s = x^y^cin;
    assign cout = (x&y)|(y&cin)|(cin&x);
endmodule 