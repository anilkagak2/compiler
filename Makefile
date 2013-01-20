a.out: main.o lex.o name.o code.o
	gcc -g main.o lex.o name.o code.o -o a.out
main.o: main.c 
	gcc -g -c main.c -o main.o
lex.o: lex.c 
	gcc -g -c lex.c -o lex.o
name.o: name.c
	gcc -g -c name.c -o name.o
code.o: code_gen.c
	gcc -g -c code_gen.c -o code.o
imp.o: improved_parser.c
	gcc -g -c basic_parser.c -o imp.o
clean: 
	rm -rf *.o a.out
