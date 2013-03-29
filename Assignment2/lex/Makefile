all: lex lexMM

lex: dfa.o nfa.o main.o
	g++ main.o dfa.o nfa.o -o lex

lexMM: dfa.o nfa.o mainMM.o
	g++ mainMM.o dfa.o nfa.o -o lexMM

mainMM.o: declarations.h main.cpp
	g++ -g -c -o mainMM.o main.cpp -D_MAXIMAL_MATCH_

main.o: declarations.h main.cpp
	g++ -g -c -o main.o main.cpp

dfa.o: dfa.cpp declarations.h
	g++ -g -c -o dfa.o dfa.cpp

nfa.o: nfa.cpp declarations.h
	g++ -g -c -o nfa.o nfa.cpp

clean:
	rm -rf *.o lex
