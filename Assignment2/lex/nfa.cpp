#include "declarations.h"


nfa::nfa () {
    num_states = 0;
}

nfa
nfa::union_nfa (nfa &n) {
}

nfa
nfa::kleene_star_nfa () {
   
    //get new rows
    vector< set<int> > start,final;
    start.resize(MAX_ALPHABET);
    final.resize(MAX_ALPHABET);

    //some definitions for clarity
    int old_start = num_states-2;
    int old_final = num_states-1;
    int new_start = num_states;
    int new_final = num_states+1;
    
    //Add 4 epsilon transitions for kleen star
    start[EPSILON].insert(old_start);    //new start -> old start
    start[EPSILON].insert(new_final);    //new start -> new final
    transitions[old_final][EPSILON].insert(new_final);    //old_final -> new final
    transitions[old_final][EPSILON].insert(old_start);    //old final -> old start

    //add start and final to transitions
    transitions.push_back(start);
    transitions.push_back(final);

    //increase num_states
    num_states += 2;
}

nfa
nfa::concate_nfa (nfa &n) {
}


