parser: dfa.o nfa.o main.o parser.o
	g++ main.o dfa.o nfa.o ll1_parser.o -o parser

parser.o: ll1_parser.h ll1_parser.cpp
	g++ -g -c -o ll1_parser.o ll1_parser.cpp

lex.o: lex.cpp declarations.h
	g++ -g -c -o lex.o lex.cpp -D_MAXIMAL_MATCH_

main.o: declarations.h ll1_parser.h main.cpp
	g++ -g -c -o main.o main.cpp 

dfa.o: dfa.cpp declarations.h
	g++ -g -c -o dfa.o dfa.cpp

nfa.o: nfa.cpp declarations.h
	g++ -g -c -o nfa.o nfa.cpp

clean:
	rm -rf *.o parser
