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

set<int>
nfa::eps_closure(int state){
	set<int>::iterator it;
	set<int> output;

	stack<int> stk;
	stk.push(state);
	while(!stk.empty()){
		int top = stk.top();
		stk.pop();
		set<int> s = transitions[top][EPSILON];
		for(it=s.begin();it!=s.end();it++){
			if(output.count(*it) == 0){
				output.insert(*it);
				stk.push(*it);
			}
		}		
	}
return output;	
}


set<int> nfa::eps_closure(set<int> state_nfa){
	set<int>::iterator it;
	set<int> output;
	
	for(it=states_nfa.begin();it != states_nfa.end();it++){
		set<int> e_closure_nfa = n.eps_closure(state);
			output.insert(e_closure_nfa.begin(),e_closure_nfa.end());
	}
	return output;
}

set<int>
nfa::move(set<int> states_nfa,char alpha){
		set<int>::iterator it;
		set<int> output;
		for(it=states_nfa.begin();it != states_nfa.end();it++){
				set<int> to_move = n.transitions[*it][alpha];
				output.insert(to_move.begin(),to_move.end());
		}
		return output;

}

/*
   ALGORITHM
   Initially, ε-closure is the only state in Dstates and it is unmarked.
   while there is an unmarked state T in Dstates
   mark T
   for each input symbol a
U:=ε-closure(move(T,a))
if U is not in Dstates then add U as unmarked to Dstates
Dtable[T,a]:=U
 */
dfa
nfa::to_dfa(){

		vector< vector<int> > Dtable;
		vector< set<int> > Dstates;
		//Dstate index which are marked
		vector<bool> marked;
		vector<bool> fianl;

		vector< set<int> >::iterator Dit;
		//Start state is defined as
		int start_state = num_states - 2;
		int final_state = num_states - 1;
		Dstates.push_back(set<int>(eps_closure(start_state)));
		marked.push_back(false);

		//Do untill all states are marked
		bool token = true;
		while(token){
				token = false;
				int i;
				for( i=0;i<marked.size();i++){
						if(marked[i] == false){
								token = true;
								break;
						}
				}
				if(token){
						marked[i] = true;
						set<char>::iterator it;
						//For each input symbol it
						for(it=alphabet.begin();it!=alphabet.end();it++){
								set<int> U = eps_closure(move(i,*it));

								int j;
								for(j=0;j<Dstates.size();j++){
										if(Dstates[j] == U){
												Dtable[i][*it] = j;
												break;
										}
								}
								//If U is not in Dstates
								if(Dtable[i][*it] != j){
										Dstates.push_back(U);
										marked.push_back(false);
										Dtable[i][*it] = Dstates.size()-1;
								}
						}
				}
		}
		for(int k=0;k< Dstates.size();k++){
			set<int> nfa_states = Dstates[k];
			if(find(nfa_states.begin(),nfa_states.end(),final_state) == nfa_states.end())
					final.push_back(false);
			final.push_back(true);

		}
		dfa converted = new dfa(Dstates.size(),alphabet,Dtable,final);
		return converted;
}
