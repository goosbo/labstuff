module gate(a,b,c,f);
	input a,b,c;
	output f;
	assign f = (a&b)|(~b&c);
endmodule
