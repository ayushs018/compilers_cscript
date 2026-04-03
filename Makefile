all:
	lex lexer.l
	yacc -d -v parser.y
	gcc lex.yy.c y.tab.c ast.c print_table.c errors.c -o a.out -lfl
	gcc gen_table.c ast.c print_table.c -o gen_table -lfl
	./gen_table

clean:
	rm -f lex.yy.c y.tab.c y.tab.h a.out parsing_table.txt