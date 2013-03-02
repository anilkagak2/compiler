#include "declarations.h"

/*
 * States	= 0,1,2, ..., numStates-1
 * numStates-2	= Start
 * numStates-1 	= final
 */
nfa::nfa (string regex) {
    num_states = 2;	// start & final
    alphabet.insert (EPSILON);

    // initialize the transitions vector & push start & final states
    transitions.resize (2);
    transitions[0].resize (MAX_ALPHABET);
    transitions[1].resize (MAX_ALPHABET);

    // base regular expression
    if (regex.length () == 1) {
	transitions[0][regex[0]].insert (1);
	return;
    }

    // complex regular expression [DEAL WITH ISSUES IF your 0->1 e-transtion creates]
    // epsilon transition
    transitions[0][EPSILON].insert (1);

    // create the nfa for the nfa
    build_nfa (regex);
}

/* 
 * Makes NFA from the regex
 */
void
nfa::build_nfa (string regex) {
	string p = regex_to_postfix (regex);	// create postfix from regular expression
	int n = p.length ();
	stack <nfa> st;

	// go on evaluate the postfix expression over the operators *,| & concate
	for (int i=0; i<n; i++) 
		switch (p[i]) {
			/* create nfa for '|' */
			case '|':
				if (!st.empty ()) {
					nfa n1 = st.top ();	st.pop ();
					if (!st.empty ()) {
						cerr << "* operator cannot be evaluated" << endl;
						exit (EXIT_FAILURE);
					}

					nfa n2 = st.top ();	st.pop ();
					n2.union_nfa (n1);
					st.push (n2);
				} else {
					cerr << "* operator cannot be evaluated" << endl;
					exit (EXIT_FAILURE);
				}
				break;

			/* create nfa for '*' */
			case '*':
				if (!st.empty ()) {
					nfa n = st.top ();
					st.pop ();
					n.kleene_star_nfa ();
					st.push (n);
				} else {
					cerr << "* operator cannot be evaluated" << endl;
					exit (EXIT_FAILURE);
				}
				break;

			default :
                string re = "";
                re += p[i];
				nfa n(re);
				st.push (n);
		}

	// now pair up the NFA's from top to bottom
	while (!st.empty ()) {
		nfa n = st.top ();
		st.pop ();
		concate_nfa (n);
	}
}

/*
 * Regular expression to postfix expression so as to 
 * ease the evaluation of operations on NFAs
 */
string
nfa::regex_to_postfix (string r) {
	int n = r.length ();
	string postfix = "";
	stack<char> st;

	// use stack to arrange operators according to the precedence
	for (int i=0; i<n; i++) 
		switch (r[i]) {
			// pop till previous operators
			case ')':
				if (!st.empty ()) {
					char op = st.top ();
					while (op != '(' && !st.empty ()) {
						postfix += op;
						st.pop ();
						op = st.top ();
					}
					if (op != '(') {
						cerr << "No matching brace for ) at " << i << endl;
						exit (EXIT_FAILURE);
					}
				} else {
					cerr << "No matching brace for ) at " << i << endl;
					exit (EXIT_FAILURE);
				}

				break;

				// union operator
			case '|': 
				while (!st.empty ()) {
					char op = st.top ();
					if (op == '|') break;
					postfix += op;
					st.pop ();
				}

				st.push ('|');
				break;

				/* for '(' & '*' just push onto the stack. */
			case '(':
			case '*':
				st.push (r[i]);
				break;

			default :
				postfix += r[i];
		}

	// pop all the operators on the stack
	while (!st.empty ()) {
		if (st.top () == '(') {
			cerr << "No matching brace for ( came in the regex " << endl;
			exit (EXIT_FAILURE);
		}
		postfix += st.top ();
		st.pop ();
	}
	return postfix;
}

/*
 * Union of two nfa's: this & n
 */
void
nfa::union_nfa (nfa &n) {
	int states_add = n.transitions.size ();

	for (int i=0; i<states_add; i++) {
		for (int j=0; j<n.transitions[i].size (); j++) {
			set<int>::iterator it;
            set<int> n_set;
			for (it=n.transitions[i][j].begin (); it != n.transitions[i][j].end (); it++) {
                n_set.insert (*it + num_states);
			}
            transitions[i][j] = n_set;
		}
		transitions.push_back (n.transitions[i]);
	}

	vector< set<int> > start_new (MAX_ALPHABET);
	vector< set<int> > final_new (MAX_ALPHABET);
	start_new[EPSILON].insert (num_states-2);			// start state of this
	start_new[EPSILON].insert (num_states + n.num_states-2);	// start state of n

	transitions[num_states-1][EPSILON].insert (num_states + n.num_states+1); // final state for new from final this
	transitions[num_states + n.num_states-1][EPSILON].insert (num_states + n.num_states+1);	// from final of n

	alphabet.insert (n.alphabet.begin (), n.alphabet.end ());
	num_states += n.num_states + 2;
	transitions.push_back (start_new);
	transitions.push_back (final_new);
}

void
nfa::kleene_star_nfa () {
  
    //get new rows
    vector< set<int> > start(MAX_ALPHABET),final(MAX_ALPHABET);

    //some definitions for clarity
    int old_start = num_states-2;
    int old_final = num_states-1;
    int new_start = num_states;
    int new_final = num_states+1;
    
    //Add 4 epsilon transitions for kleen star
    start[EPSILON].insert(old_start);    //new start -> old start
    start[EPSILON].insert(new_final);    //new start -> new final
    transitions[old_final][EPSILON].insert(new_final);    //old_final -> new final
    transitions[old_final][EPSILON].insert(old_start);    //old final -> old start

    //add start and final to transitions
    transitions.push_back(start);
    transitions.push_back(final);

    //increase num_states
    num_states += 2;
}

void
nfa::concate_nfa (nfa &n) {
    int states_add = n.transitions.size ();

	for (int i=0; i<states_add; i++) {
		for (int j=0; j<n.transitions[i].size (); j++) {
			set<int>::iterator it;
            set<int> n_set;
			for (it=n.transitions[i][j].begin (); it != n.transitions[i][j].end (); it++) {
                n_set.insert (*it + num_states);
			}
            transitions[i][j] = n_set;
		}
		transitions.push_back (n.transitions[i]);
	}

    /*
	vector< set<int> > start_new (MAX_ALPHABET);
	vector< set<int> > final_new (MAX_ALPHABET);
	start_new[EPSILON].insert (num_states-2);			// start state of this
	start_new[EPSILON].insert (num_states + n.num_states-2);	// start state of n
    */
    
    //some definitions for clarity
    int old_start_1 = num_states-2;
    int old_final_1 = num_states-1;
    int old_start_2 = num_states + n.num_states - 2;
    int old_final_2 = num_states + n.num_states - 1;
    
	transitions[old_final_1][EPSILON].insert (old_start_2);	// old_final_1 -> old_start_2 

    /*
	transitions.push_back (start_new);
	transitions.push_back (final_new);
	*/

    vector< set<int> > start_row;
	start_row = transitions[old_start_1];
    transitions.erase(transitions.begin() + old_start_1);
    transitions.insert(transitions.begin()+transitions.size()-2,start_row);
    
	for (int i=0; i<transitions.size(); i++) {
		for (int j=0; j<transitions[i].size (); j++) {
			set<int>::iterator it;
            set<int> n_set;
            for (it=n.transitions[i][j].begin (); it != n.transitions[i][j].end (); it++) {
                
                if(*it >= (num_states-1) && *it <= (num_states + n.num_states - 2)){
                    //*it -= 1;	// decrement the state index with 1 if its index was changed during erase and insert process.
			        n_set.insert(*it-1);
                }
                else 
                n_set.insert(*it);
            }
            transitions[i][j] = n_set;
		}
	}
    
    alphabet.insert (n.alphabet.begin (), n.alphabet.end ());
	num_states += n.num_states;

}




