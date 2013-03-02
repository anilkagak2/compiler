#include "declarations.h"

int main() {
    //string re = "ab";
    //re = "a|b";
    
    vector<string> regex;
    regex.push_back("a|b");
    regex.push_back("a*");


    vector<dfa> dfas;

    for(int i=0 ; i< regex.size(); i++){
        nfa n(regex[i]);
        dfas.push_back(n.to_dfa());    
    }
    
    //d.print_transitions ();
	//d.print_final();
    string input;
    cin >> input;

    int current=0;
    while(current < input.length()){
       
        vector<string> buffer(dfas.size());
        vector<int> max_num_chars_to_final(dfas.size(),-1);

        /*
        //If dfa i accepts the string then final state is stored in 
        //this vector and -1 otherwise
        vector<int> dfa_accept(dfas.size(),-1);
        */
        int max_advance = -1;
        for(int j=0;j < dfas.size() ; j++){
            //Do not advance if the next state is rejecting
            for(int i =0; (!dfas[j].peek_rejecting(input[current+i])) && (current+i < input.length()); i++){
            
                if(dfas[j].final[dfas[j].current_state]){
                    max_num_chars_to_final[j] = i;
                }
                dfas[j].advance(input[current+i]);
            }
            if(max_num_chars_to_final[j] > max_advance) max_advance = max_num_chars_to_final[j];
        }

        if(max_advance == -1 || max_advance == 0) {
            cout << "Error in lexical Analysis" <<endl; 
            exit(1);
        }

        int accepting_dfa = -1;
        for(int j=0;j < dfas.size() ; j++){
            if(max_num_chars_to_final[j] == max_advance){
                accepting_dfa = j;
                break;
            }
        }

        string output(input[current],input[current+max_advance]);
        cout << accepting_dfa <<" "<<output << endl;

        current += max_advance;

        /* -1 -> next is rejecting && present is not final
         *  0 -> " && present is final
         */
    }
    
    return 0;
}
