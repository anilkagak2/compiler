#include "declarations.h"

    

dfa::dfa (){
    num_states = 0;
}

dfa::dfa (int num_states,set<char>
					alphabet,
					vector<vector<int> >
					transitions,vector<bool> final);

	this.num_states = num_states;
	this.alphabet = alphabet;
	this.final = final;
	this.transitions = transitions;	
}




