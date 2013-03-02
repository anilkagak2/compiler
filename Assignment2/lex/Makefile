lex: dfa.o nfa.o main.o
	g++ main.o dfa.o nfa.o -o lex

main.o: declarations.h main.cpp
	g++ -g -c -o main.o main.cpp

dfa.o: dfa.cpp declarations.h
	g++ -g -c -o dfa.o dfa.cpp

nfa.o: nfa.cpp declarations.h
	g++ -g -c -o nfa.o nfa.cpp

clean:
	rm -rf *.o lex
