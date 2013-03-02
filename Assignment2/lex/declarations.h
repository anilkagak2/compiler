#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

#define EPSILON	'$'
#define MAX_ALPHABET 256

class dfa;

class nfa {
    
    int num_states;
    set<char> alphabet;
    vector< vector< set<int> > > transitions;

    nfa (string regex);
    dfa to_dfa (); 
    void union_nfa (nfa &n);
    void kleene_star_nfa ();
    void concate_nfa (nfa &n);
	set<int> eps_closure(int state);
	set<int> eps_closure(set<int> state);
	set<int> move(set<int> states,char alpha);
    
	void build_nfa (string regex);
	string regex_to_postfix (string regex);
};

class dfa {
    
    int num_states;
    set<char> alphabet;
    vector<bool> final;
    vector< vector<int> > transitions;

//Set of states of DFA mapped with the set of corresponding states of NFA
	// eg : Dstates[1] = {1,2,3}
	vector< set<int> > Dstates;
    
	dfa ();
    public:
    dfa (int num_states,set<char> alphabet,vector<vector<int> > transitions,vector<bool> final);
    
    	bool match(string s);
};

