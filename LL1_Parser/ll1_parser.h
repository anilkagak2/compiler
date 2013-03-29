#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

/* Class representing the abstract notion of NonTerminals */
class NonTerminal {
	public:
		NonTerminal ();
		void addProductions (string p);

		bool nullable;
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
		Grammar(char* fileName);

	private:
		map<string, NonTerminal> nonTerminals;
		set<string>		 terminals;
		void calcNullable();
		string 			 start;
		void populateFirst();
		void populateFollow();
		void makeParse();
		void parse(string);

		/* Follow: Helper functions. */
		inline bool isNonTerminal (string nt) {
			return nonTerminals.find (nt) != nonTerminals.end ();
		}

		inline bool isTerminal (string nt) {
			return terminals.find (nt) != terminals.end ();
		}

		/* Calculates the First set of a production. */
		set<string> firstOf (string production);

		/* Calculates the Nullability of a production. */
		bool nullable (string production);
};

