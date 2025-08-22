module q1(a,b,c,d,f);
    input a,b,c,d;
    output f;
    nand(b1,b,b); 
    nand(g,a,b1);
    nand(d1,d,d);
    nand(h,c,d1);
    nand(f1,g,h);
    nand(f,f1,f1);
endmodule