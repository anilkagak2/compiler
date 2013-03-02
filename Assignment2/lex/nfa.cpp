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
        alphabet.insert (regex[0]);
    	transitions[0][regex[0]].insert (1);
    	return;
    }

    // complex regular expression [DEAL WITH ISSUES IF your 0->1 e-transtion creates]
    // epsilon transition
    transitions[0][EPSILON].insert (1);

    // create the nfa for the nfa
    build_nfa (regex);
}

void
nfa::print_transitions () {
    cout << "BEGIN DELTA" << endl;
    for (int i=0; i<transitions.size (); i++) {
        cout << i <<  "--> ";
		set<char>::iterator p;
	    for (p=alphabet.begin (); p != alphabet.end (); p++) {
                cout << *p << " ";
                set<int>::iterator it;
                for (it=transitions[i][*p].begin (); it != transitions[i][*p].end (); it++) {
                    cout << *it << " ";
                }
                cout << " : " ;
        }
        cout << endl;
    }
    cout << "END DELTA" << endl;
}

string
nfa::complex_to_base (string r) {
	string ret = "";
	for (int i=0; i<r.length (); i++) {
		if (r[i] == '[') {
			int pos = r.find_first_of (']', i+1);
			if (pos != string::npos) {
		 	    char st = r[++i];
			    char end = r[++i];
			    if (r[++i] != ']') {
				cerr << "Currently this range operator is not supported\n";
				exit (EXIT_FAILURE);
			    }
			    else {
				ret += "(";
				for (int i=0; i<end-st; i++) {
					stringstream ss;
					ss << st+i;
					ret += ss.str ();
					if (st+i != end-1) ret += "|";
				}
				ret += ")";
			    }
			}
		} else ret += r[i];
	}
	return ret;
}

/* 
 * Makes NFA from the regex
 */
void
nfa::build_nfa (string regex) {
    string p = regex_to_postfix (regex);	// create postfix from regular expression
    cout << "postfix is " << p << endl;
    int n = p.length ();
    stack <nfa> st;

    // go on evaluate the postfix expression over the operators *,| & concate
    for (int i=0; i<n; i++) 
        switch (p[i]) {
            /* create nfa for '|' */
            case '|':
                if (!st.empty ()) {
                    nfa n1 = st.top ();	st.pop ();
                    if (st.empty ()) {
                        cerr << "| operator cannot be evaluated" << endl;
                        exit (EXIT_FAILURE);
                    }

                    nfa n2 = st.top ();	st.pop ();
                    cout << "UNION " << endl;
                    n2.union_nfa (n1);
                    n2.print_transitions ();
                    cout << "UNION END" << endl;
                    st.push (n2);
                } else {
                    cerr << "| operator cannot be evaluated" << endl;
                    exit (EXIT_FAILURE);
                }
                break;

            /* create nfa for concatenation */
            case CONCATE:
                if (!st.empty ()) {
                    nfa n1 = st.top ();	st.pop ();
                    if (st.empty ()) {
                        cerr << "concate operator cannot be evaluated" << endl;
                        exit (EXIT_FAILURE);
                    }

                    nfa n2 = st.top ();	st.pop ();
                    cout << "CONCATE " << endl;
                    n2.concate_nfa (n1);
                    n2.print_transitions ();
                    cout << "CONCATE END" << endl;
                    st.push (n2);
                } else {
                    cerr << "concate operator cannot be evaluated" << endl;
                    exit (EXIT_FAILURE);
                }
                break;

                /* create nfa for '*' */
            case '*':
                if (!st.empty ()) {
                    nfa n = st.top ();
                    st.pop ();
                    n.kleene_star_nfa ();
                    cout <<"KLEENE " << endl;
                    n.print_transitions ();
                    cout <<"KLEENE END" << endl;
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
                n.print_transitions ();
                st.push (n);
        }

    // b
    nfa a = st.top (); st.pop ();

    // now pair up the NFA's from top to bottom
    while (!st.empty ()) {
        nfa n = st.top ();      // a
        st.pop ();
        n.concate_nfa (a);      // ab
        a = n;             
    }

    cout<<"final: "<<endl;
    a.print_transitions ();
    *this = a;
}

/*
 * Cases where CONCATE operator should occur
 */
string
nfa::insert_concate_op (string r) {
	string ct; ct=CONCATE;
	if (r.length () == 1) return r;		// base case

	string ret = "";
	ret += r[0];
	char p = r[0];
	for (int i=1; i<r.length (); i++) {
		if ((p=='*' && r[i]=='(') ||
		    (p=='*' && (r[i] != '*' && r[i]!='|' && r[i]!=')' && r[i]!='(')) ||
		    (p==')' && (r[i] != '*' && r[i]!='|' && r[i]!=')' && r[i]!='(')) ||
		    (r[i]=='(' && (p != '*' && p!='|' && p!=')' && p!='(')) ||
		    ((r[i] != '*' && r[i]!='|' && r[i]!=')' && r[i]!='(') 
			&& (p != '*' && p!='|' && p!=')' && p!='('))) ret += ct + r[i];
		else ret += r[i];
		p = r[i];
	}
	return ret;
}

/*
 * Regular expression to postfix expression so as to 
 * ease the evaluation of operations on NFAs
 */
string
nfa::regex_to_postfix (string r) {
    r = insert_concate_op (r);
    cout << "concate operator inserted: " << r << endl;
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
                        cout << "postfix " << postfix << endl;
                        st.pop ();
                        op = st.top ();
                    }
                    if (op != '(') {
                        cerr << "No matching brace for ) at " << i << endl;
                        exit (EXIT_FAILURE);
                    }
                    st.pop ();  // pop '('
                } else {
                    cerr << "No matching brace for ) at " << i << endl;
                    exit (EXIT_FAILURE);
                }

                break;

                // union operator
            case '|': 
                while (!st.empty () && (st.top()==CONCATE)) {
                    char op = st.top ();
                    if (op == '|') break;
                    postfix += op;
                    st.pop ();
                }

                st.push ('|');
                break;

                // concate operator
            case CONCATE: 
                if (!st.empty () && (st.top()==CONCATE)) {
                    char op = st.top ();
                    postfix += op;
                    st.pop ();
                }

                st.push (CONCATE);
                break;

                /* for '(' & '*' just push onto the stack. */
            case '(':
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

    /*cout <<"my transitions " << endl;
    print_transitions () ;
    cout << "n's trans " ;
    n.print_transitions ();*/
    for (int i=0; i<states_add; i++) {
        for (int j=0; j<n.transitions[i].size (); j++) {
            set<int>::iterator it;
            set<int> n_set;
            for (it=n.transitions[i][j].begin (); it != n.transitions[i][j].end (); it++) {
//                cout << "*it+num_states " << *it+num_states <<" i j " << i <<" " << j << endl;
                n_set.insert (*it + num_states);
            }
            // 
            n.transitions[i][j] = n_set;
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

    alphabet.insert (n.alphabet.begin (), n.alphabet.end ());
 /*   cout<<"IN concate"<<endl;
    print_transitions();
    n.print_transitions(); */
    for (int i=0; i<states_add; i++) {
        for (int j=0; j<n.transitions[i].size (); j++) {
            set<int>::iterator it;
            set<int> n_set;
            for (it=n.transitions[i][j].begin (); it != n.transitions[i][j].end (); it++) {
                n_set.insert (*it + num_states);
//                cout<< i <<" "<<j<<" "<<*it+num_states<<endl;
            }
            n.transitions[i][j] = n_set;
        }
        transitions.push_back (n.transitions[i]);
    }
   
  //  print_transitions();
    //some definitions for clarity
    int old_start_1 = num_states-2;
    int old_final_1 = num_states-1;
    int old_start_2 = num_states + n.num_states - 2;
    int old_final_2 = num_states + n.num_states - 1;

    transitions[old_final_1][EPSILON].insert (old_start_2);	// old_final_1 -> old_start_2 
 
    vector< set<int> > start_row;
    start_row = transitions[old_start_1];
    transitions.erase(transitions.begin() + old_start_1);
    transitions.insert(transitions.begin()+num_states+n.num_states-2,start_row);

    for (int i=0; i<transitions.size(); i++) {
        for (int j=0; j<transitions[i].size (); j++) {
            set<int>::iterator it;
            set<int> n_set;
            for (it=transitions[i][j].begin (); it != transitions[i][j].end (); it++) {
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

    num_states += n.num_states;
    //cout << "UTPUT concat " << endl;
    //print_transitions();
}


void show_set(set<int> s){
		set<int>::iterator it;
		for(it=s.begin();it!=s.end();it++){
				cout << " " << *it;
		}

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
		output.insert(top);		
    }
//	cout << "\ne-closure of state : "<<state <<" : ";
//	show_set(output);

    return output;	
}


set<int> nfa::eps_closure(set<int> states_nfa){
    set<int>::iterator it;
    set<int> output;

    for(it=states_nfa.begin();it != states_nfa.end();it++){
        set<int> e_closure_nfa = eps_closure(*it);
        output.insert(e_closure_nfa.begin(),e_closure_nfa.end());
    }
//	cout << "\n e-closure of ";show_set(states_nfa);
//	cout << " is ---> ";show_set(output);
    return output;
}

set<int>
nfa::move(set<int> states_nfa,char alpha){
    set<int>::iterator it;
    set<int> output;
    for(it=states_nfa.begin();it != states_nfa.end();it++){
        set<int> to_move = transitions[*it][alpha];
        output.insert(to_move.begin(),to_move.end());
    }
//	cout << "\nin move for " << alpha << endl;
//	cout << "\ninput set ";show_set(states_nfa);
//	cout << "\noutput set ";show_set(output);
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
    vector<bool> final;

    vector< set<int> >::iterator Dit;
    //Start state is defined as
    int start_state = num_states - 2;
    int final_state = num_states - 1;
    Dstates.push_back(set<int>(eps_closure(start_state)));
    marked.push_back(false);

	//Row containing the mappig of current states with all alphabet 
	vector<int> row_alpha(MAX_ALPHABET,-1);

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

            //For each input symbol 
            for(it=alphabet.begin();it!=alphabet.end();it++){
                if(*it == EPSILON)
						continue;
				
				set<int> U = eps_closure(move(Dstates[i],(*it)));
				int j;
				bool is_present = false;
				for(j=0;j<Dstates.size();j++){
						if(Dstates[j] == U){
							row_alpha[*it] = j;
							is_present = true;
							break;
						}
				}
			
				//cout << "in to_dfa\n";
				//If U is not in Dstates
				if(!is_present){
						Dstates.push_back(U);
						marked.push_back(false);
						row_alpha[*it] = Dstates.size()-1;
				}
			}

				Dtable.push_back(row_alpha);
		}
	}
//	cout << "\nDstates " << endl;
	for(int k=0;k< Dstates.size();k++){
			set<int> nfa_states = Dstates[k];
//			cout << "\n " << k << " : ";show_set(nfa_states);
			if(find(nfa_states.begin(),nfa_states.end(),final_state) == nfa_states.end())
					final.push_back(false);
			else
					final.push_back(true);

	}
	set<char> alp_without_epsilon = alphabet;
	alp_without_epsilon.erase(EPSILON);
	dfa converted(Dstates.size(),alp_without_epsilon,Dtable,final);
	return converted;
}

