module q3(a,b,c,d,f);
    input a,b,c,d;
    output f;
    assign f = (a&b&d)|(a&b&c)|(b&c&d)|(a&c&d);
endmodule 