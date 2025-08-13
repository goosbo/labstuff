module q1_gate(a,b,c,d,f);
	input a,b,c,d;
	output f;
	and(g,a,b);
	or(h,g,c);
	not(h1,h);
	and(i,h1,d);
	or(j,h,d);
	and(f,i,j);
endmodule
