#include "ll1_parser.h"

using namespace std;

/* $ symbol */
const string dollar="DOLLAR";


/* Calculate the follow sets of the NonTerminals */
void
Grammar::populateFollow () {
	// add dollar to the followSet of start symbol
	if (!isNonTerminal (start)) {
		cout << "Error Follow:No start non-terminal symbol in the grammar"
			 << endl;
		exit (EXIT_FAILURE);
	}

	nonTerminals[start].followSet.insert (dollar);

	map<string, NonTerminal> it;
	while (1) {
	bool change = false;
	for (it=nonTerminals.begin (); it!=nonTerminals.end (); it++) {
		vector<string> P = it->second->productions;
		for (int i=0; i<P.size (); i++) {
			stringstream ss (P[i]);
			string nt, reverse_pi;

			// P[i]->x1 x2 x3.. xn
			// 1 to n-1, although it'll go till n but the nth first will be empty
			while (ss >> nt) {
				reverse_pi += nt + " ";
				if (isNonTerminal (nt)) {
					set<string> f_next = firstOf (ss.str ());
					bool inserted = NonTerminal[nt].followSet.insert (f_next.begin (), f_next.end ()).second;
					change |= inserted;
				}
			}
		
			// TODO delete the last space	
			// n to 1
			ss.str (reverse_pi);
			while (ss >> nt) {
				if (isNonTerminal (nt) && nullable (ss.str ())) {
					set<string> followPI = it->followSet;	// follow set of the current NT
					bool inserted = NonTerminal[nt].followSet.insert (followPI.begin (), followPI.end ()).second;
					change |= inserted;
				}
			}
		}
	}

	// if no change in any follow set, break the while loop
	if (!change) break;
	}
}

/* Calculates the Nullability of a production. */
bool 
Grammar::nullable (string P) {
	if (P == "") return true;

	stringstream ss (P);
	string nt;
	ss >> nt;

	// TODO check for trailing whitespaces in the ss stream
	if (isNonTerminal (nt) && !nonTerminals[nt].nullable) return false;
	else return nullable (ss.str ());
}

/* Calculates the First set of a production.
 * Recursion shouldn't be the bottolneck
 */
set<string> &
Grammar::firstOf (string production) {
	stringstream ss (production);
	string nt;
	set<string> first;

	ss >> nt;
	if (nt != "") {
		if (isTerminal (nt)) {
			first.insert (nt);
			break;
		}

		bool isNt = isNonTerminal (nt);
		if (!isNt) {
			cout << "Error firstOf: Symbol not in the grammar"
				<< endl;
			exit (EXIT_FAILURE);
		}

		if (isNt && !nonTerminals[nt].nullable)
			return nonTerminals[nt].firstSet;

		first.insert (nonTerminals[nt].firstSet.begin (),
				nonTerminals[nt].firstSet.end ());
		set<string> f_next = firstOf (ss.str ());
		first.insert ( f_next.begin (), f_next.end ());
	}

	return first;
}
