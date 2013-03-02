#include "declarations.h"

    

dfa::dfa (){
    num_states = 0;
}

dfa::dfa(nfa n){
	this.n = n;	
}

set<int> dfa::move(int state,char alpha){
	set<int>::iterator it;
	set<int> output;
	
	set<int> states_nfa = Dstates[state];
	for(it=states_nfa.begin();it != states_nfa.end();it++){
		set<int> to_move = n.transitions[*it][alpha];
		output.insert(to_move.begin(),to_move.end());
	}
	return output;
}
