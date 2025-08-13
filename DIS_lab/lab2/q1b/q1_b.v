module q1_b(a,b,c,d,f);
    input a,b,c,d;
    output f;
    assign f = (b&~c&~d)|(~a&~c)|(~b&d)|(~b&c);
endmodule 