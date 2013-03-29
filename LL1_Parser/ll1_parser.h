#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>

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
		Grammar ();

	private:
		map<string, NonTerminal> nonTerminals;
		set<string>		 terminals;
		string 			 start;
		void populateFirst();
		void populateFollow();
		void makeParse();

		/* Follow: Helper functions. */
		inline bool isNonTerminal (string nt) {
			return nonTerminals.find (nt) != nonTerminals.end ();
		}

		inline bool isTerminal (string nt) {
			return terminals.find (nt) != terminals.end ();
		}

		/* Calculates the First set of a production. */
		set<string> &firstOf (string production);

		/* Calculates the Nullability of a production. */
		bool nullable (string production);
};

