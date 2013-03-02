#include "declarations.h"

    

dfa::dfa (){
    num_states = 0;
}

bool
dfa::match(string s){
    int cur_state = num_states - 2;
    for(int i=0; i<s.length(); i++){
        cur_state = transitions[cur_state][s[i]];
    }
    if(final[cur_state])return true;
    else return false;
}
