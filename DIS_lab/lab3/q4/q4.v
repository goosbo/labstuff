module q4(a,b,c,d,f);
    input a,b,c,d;
    output f;
    nand(d1,d,d);
    nand(g,b,d1);
    nand(h,a,d);
    nand(f1,g,h);
    nand(f,f1,f1);
endmodule