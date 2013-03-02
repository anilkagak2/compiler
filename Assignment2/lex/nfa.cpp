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
}

nfa
nfa::kleene_star_nfa () {
}

nfa
nfa::concate_nfa (nfa &n) {
}


