#include "ll1_parser.h"
#include "lex.cpp"

using namespace std;

int main () {
//	lex ();
//	ifstream lexeme("lex_output.txt");
	ifstream grammar("grammar.txt");
	
	Grammar g("grammar.txt");
	g.printNonTerminals();
	cout << endl;
	g.printTerminals();
	cout << endl;
	g.printFirstSet();
	cout << endl;
	g.printFollowSet();
	cout << endl;
	g.printParseTable();
	cout << endl;

    //ifstream input("lex_output.txt");
	lex ();
    string input = get_file_contents("lex_output.txt");
    cout << "Parser: begin Input tokens "<<endl;
    cout << input << endl;
    cout << "Parser: end Input tokens "<<endl;
    g.parse(input);

};
