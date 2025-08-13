module q1_continuous(a,b,c,d,f);
	input a,b,c,d;
	output f;
	wire f1;
	assign f1 = (a&b)|c;
	assign f = (~f1&d)&(f1|d);
endmodule
