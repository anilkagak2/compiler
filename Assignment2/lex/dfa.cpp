#include "declarations.h"


void
dfa::reset(){
    current_state = num_states - 2; 
}

bool 
dfa::peek_rejecting(char c){
    return rejecting[transitions[current_state][c]]; 
}

void 
dfa::advance(char c){
    current_state = transitions[current_state][c];
}

dfa::dfa (int num_states, set<char>alphabet,vector<vector<int> >	transitions,vector<bool> final){

	this->num_states = num_states;
	this->alphabet = alphabet;
	this->final = final;
	this->transitions = transitions;	
   
    calculate_reject();
}

void 
dfa::calculate_reject(){
    rejecting.resize(num_states);
    for(int i=0 ; i<num_states; i++){
        
        bool can_not_reach_final = true;
        queue<int> q;
        vector<bool> done(num_states,0);
        
        q.push(i);
        done[i] = 1;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            done[top] = 1;

            if(final[top]){
                can_not_reach_final = false;
                break;
            }

            for(int j=0; j<transitions[top].size(); j++){
                if( (transitions[top][j] != -1) && (!done[transitions[top][j]]) ) q.push(j);
            }
        }

        rejecting[i] = can_not_reach_final; //TODO: declare rejecting array 
    }
}


void
dfa::print_transitions () {
    cout << "----------------BEGIN DFA" << endl;
    for (int i=0; i<transitions.size (); i++) {
        cout << i <<  "--> ";
		set<char>::iterator p;
	    for (p=alphabet.begin (); p != alphabet.end (); p++) {
                cout << *p << " ";
                //set<int>::iterator it;
               // for (it=transitions[i][*p].begin (); it != transitions[i][*p].end (); it++) {
                    cout << transitions[i][*p] << " ";
                //}
                cout << " : " ;
        }
        cout << endl;
    }
    cout << "---------------END DFA" << endl;
}

void
dfa::print_final(){
	for(int i =0 ;i<final.size();i++){
		//	cout << "\nsize" << final.size();
		if(final[i] == true)
				cout << " " << i;
	}
	
}
