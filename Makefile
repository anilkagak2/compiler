a.out: main.o lex.o name.o code.o
	gcc main.o lex.o name.o code.o -o a.out
main.o:
	gcc -c main.c -o main.o
lex.o:
	gcc -c lex.c -o lex.o
name.o:
	gcc -c name.c -o name.o
code.o:
	gcc -c code_gen.c -o code.o
imp.o:
	gcc -c basic_parser.c -o imp.o
clean: 
	rm -rf *.o a.out
