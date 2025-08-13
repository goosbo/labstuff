module q2_gate(a,b,c,d,f,g);
	input a,b,c,d;
	output f,g;
	nand(h,a,b);
	xor(f,h,c,d);
	nor(g,b,c,d);
endmodule
