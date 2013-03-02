#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>


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

