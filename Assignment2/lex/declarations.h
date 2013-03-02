#include <cstdio>
#include <iostream>
#include <cstlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

class nfa {
    
    int num_states;
    map<char,int> alphabet;
    //vector<bool> final;
    int final;
    vector< vector< set<int> > > transitions;

        nfa ();
    dfa to_dfa (); 
    nfa union_nfa (nfa &n);
    nfa kleene_star_nfa ();
    nfa concate_nfa (nfa &n);
};

class dfa {
    
    int num_states;
    map<char,int> alphabet;
    vector<bool> final;
    vector< vector<int> > transitions;

    dfa ();
};

