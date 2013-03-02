#include "declarations.h"

/*
 * States	= 0,1,2, ..., numStates-1
 * numStates-2	= Start
 * numStates-1 	= final
 */
nfa::nfa () {
    num_states = 2;	// start & final
    alphabet.insert (EPSILON);

    transitions.resize (2);
    transitions[0].resize (MAX_ALPHABET);
    transitions[1].resize (MAX_ALPHABET);

    // epsilon transition
    transitions[0][EPSILON].insert (1);
}

nfa
nfa::union_nfa (nfa &n) {
	int states_add = n.transitions.size ();

	for (int i=0; i<states_add; i++) {
		for (int j=0; j<n.transitions[i].size (); j++) {
			set<int>::iterator it;
			for (it=n.transitions[i][j].begin (); it != n.transitions[i][j].end (); it++) {
				*it += num_states;	// increment the state index with this->new_states
			}
		}
		transitions.push_back (n.transitions[i]);
	}

	vector< set<int> > start_new (MAX_ALPHABET);
	vector< set<int> > final_new (MAX_ALPHABET);
	start_new[EPSILON].insert (num_states-2);			// start state of this
	start_new[EPSILON].insert (num_states + n.num_states-2);	// start state of n

	transitions[num_states-1][EPSILON].insert (num_states + n.num_states);	// final state for new from final this
	transitions[num_states + n.num_states-1][EPSILON].insert (num_states + n.num_states);	// from final of n

	alphabet.insert (n.alphabet.begin (), n.alphabet.end ());
	num_states += n.num_states + 2;
	transitions.push_back (start_new);
	transitions.push_back (final_new);
}

nfa
nfa::kleene_star_nfa () {
}

nfa
nfa::concate_nfa (nfa &n) {
}


