#include <cstdio>
#include <iostream>
#include <cstlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define EPSILON	'$'
#define MAX_ALPHABET 256

class nfa {
    
    int num_states;
    set<char> alphabet;
    vector< vector< set<int> > > transitions;

        nfa (string regex);
    dfa to_dfa (); 
    nfa union_nfa (nfa &n);
    nfa kleene_star_nfa ();
    nfa concate_nfa (nfa &n);

    private:
	void build_nfa (string regex);
	string regex_to_postfix (string regex);
};

class dfa {
    
    int num_states;
    //map<char,int> alphabet;
    set<char> alphabet;
    vector<bool> final;
    vector< vector<int> > transitions;

    dfa ();
    bool match(string s);
};

