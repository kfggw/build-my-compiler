
clean:
	rm demo.tab.* lex.yy.c demo

build:
	bison -d demo.y && flex demo.l && gcc demo.tab.c lex.yy.c -o demo