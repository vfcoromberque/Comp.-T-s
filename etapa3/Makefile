etapa3: main.o lex.yy.o y.tab.o hash.o ast.o
	gcc main.o lex.yy.o y.tab.o hash.o ast.c -o etapa3

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

ast.o: ast.c
	gcc -c ast.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.c: parser.y
	yacc -d parser.y
	
lex.yy.c: scanner.l 
	lex scanner.l
	
clean: 
	rm *.o etapa3 lex.yy.c y.tab.c


# flex scanner.l
# bison -d parser.y
# gcc -c lex.yy.c
# gcc -c parser.tab.c
# gcc -c ast.c
# gcc -c hash.c
# gcc -c main.c
# gcc main.o lex.yy.o parser.tab.o hash.o ast.c -o etapa3