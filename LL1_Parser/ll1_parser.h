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
#include <numeric>

using namespace std;

/* Class representing the abstract notion of NonTerminals */
class NonTerminal {
	public:
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
		Grammar(string fileName);
		void parse(string);
		void printNonTerminals();
		void printTerminals();
		void printProductions ();
		void printFirstSet();
		void printFollowSet();
		void printParseTable();

	private:
		map<string, NonTerminal> nonTerminals;
		set<string>		 terminals;
		void calcNullable();
		string 			 start;
		void populateFirst();
		void populateFollow();
		void makeParse();
	        void leftFactor();

		/* Follow: Helper functions. */
		inline bool isNonTerminal (string nt) {
			return nonTerminals.find (nt) != nonTerminals.end ();
		}

		inline bool isTerminal (string nt) {
			return terminals.find (nt) != terminals.end ();
		}

		/* number to string */
		string numToString (int i) {
			stringstream ss;
			ss << i;
			return ss.str ();
		}

		/*
		   If str is a nonTerminal then adds FIRST[str] to that of nt
		   If str is a Terminal then adds it to the first set
		   Returns true is there has been change in the first set
		 */ 
		bool addFirst(NonTerminal &nt,string str);

		/* Calculates the First set of a production. */
		set<string> firstOf (string production);

		/* Calculates the Nullability of a production. */
		bool nullable (string production);

		/* Remove indirect left recursion. */
		void removeIndirectLeftRecursion ();

		/* Remove direct left recursion. */
		bool removeDirectLeftRecursion (string nt, vector<string> &);

		/* Generate name for the new NonTerminal. */
		string generateName (string nt);

		/* Utilities */
		void substr_token(string s,int front_tokens,string &front,string &back);
};

