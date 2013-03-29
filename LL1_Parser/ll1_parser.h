#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/* Class representing the abstract notion of NonTerminals */
class NonTerminal {
	public:
		NonTerminal (string p);
		~ NonTerminal ();
		void addProductions (string p);


		set<string> 		firstSet;
		set<string> 		followSet;
		map<string, string>	parseTable;
		vector<string>		productions;
};

/* Class representing the abstract notion of Grammars
 * (Terminals, Non-Terminals, StartSymbol, Productions)
 */
class Grammar {
	public:

	private:
		map<string, NonTerminal> nonTerminals;
		set<string>		 terminals;
};
