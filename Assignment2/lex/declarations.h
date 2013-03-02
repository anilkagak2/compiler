#include <cstdio>
#include <iostream>
#include <cstlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define EPSILON	'$'
#define MAX_ALPHABET 256

class nfa {
    
    int num_states;
//    map<char,int> alphabet;
    set<char> alphabet;
    //vector<bool> final;
//    int final;
    vector< vector< set<int> > > transitions;

        nfa ();
    dfa to_dfa (); 
    nfa union_nfa (nfa &n);
    nfa kleene_star_nfa ();
    nfa concate_nfa (nfa &n);
	set<int> eps_closure(int state);
	set<int> eps_closure(set<int> state);
	set<int> move(set<int> states,char alpha);

};

class dfa {
    
    int num_states;
//    map<char,int> alphabet;
	set <char> alphabet;
	 vector<bool> final;
    vector< vector<int> > transitions;

	//Set of states of DFA mapped with the set of corresponding states of NFA
	// eg : Dstates[1] = {1,2,3}
	vector< set<int> > Dstates;
    
	dfa ();
	dfa (int num_states,set<char>
					alphabet,
					vector<vector<int> >
					transitions,vector<bool> final);
};


