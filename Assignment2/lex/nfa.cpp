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

void
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

void
nfa::kleene_star_nfa () {
   
    //get new rows
    vector< set<int> > start(MAX_ALPHABET),final(MAX_ALPHABET);

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

void
nfa::concate_nfa (nfa &n) {
    
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

    /*
	vector< set<int> > start_new (MAX_ALPHABET);
	vector< set<int> > final_new (MAX_ALPHABET);
	start_new[EPSILON].insert (num_states-2);			// start state of this
	start_new[EPSILON].insert (num_states + n.num_states-2);	// start state of n
    */
    
    //some definitions for clarity
    int old_start_1 = num_states-2;
    int old_final_1 = num_states-1;
    int old_start_2 = num_states + n.num_states - 2;
    int old_final_2 = num_states + n.num_states - 1;
    
	transitions[old_final_1][EPSILON].insert (old_start_2);	// old_final_1 -> old_start_2 

    /*
	transitions.push_back (start_new);
	transitions.push_back (final_new);
	*/

    vector< set<int> > start;
	start_row = transitions[old_start_1];
    transitions.erase(old_start_1);
    transitions.insert(transitions.begin()+transitions.size()-2,start_row);
    
	for (int i=0; i<transitions.size(); i++) {
		for (int j=0; j<transitions[i].size (); j++) {
			set<int>::iterator it;
			for (it=n.transitions[i][j].begin (); it != n.transitions[i][j].end (); it++) {
                
                if(*it >= (num_states-1) && *it <= (num_states + n.num_states - 2)){
                    *it -= 1;	// decrement the state index with 1 if its index was changed during erase and insert process.
			    }
            }
		}
	}
    
    alphabet.insert (n.alphabet.begin (), n.alphabet.end ());
	num_states += n.num_states;

}

set<int> 
nfa::eps_closure(int state){
    set<int> to_return;
}



