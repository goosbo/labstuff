module q2(a,b,c,d,f);
    input a,b,c,d;
    output f;
    nor(d1,d,d);
    nor(g,a,c,d1);
    nor(h,b,d);
    nor(i,b,c);
    nor(f1,g,h,i);
    nor(f,f1,f1);
endmodule

