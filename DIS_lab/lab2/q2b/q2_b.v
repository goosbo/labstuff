module q2_b(a,b,c,d,f);
    input a,b,c,d;
    output f;
    assign f = (~b|c|d)&(~a|b|~d)&(~a|b|~c)&(a|~c|d);
endmodule 