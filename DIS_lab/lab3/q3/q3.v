module q3(a,b,c,d,f);
    input a,b,c,d;
    output f;
    nor(d1,d,d);
    nor(g,a,d1);
    nor(h,c,d1);
    nor(f1,g,h);
    nor(f,f1,f1);
endmodule