#include "ll1_parser.h"

using namespace std;

/* $ symbol */
const string dollar="DOLLAR";
const string EPSILON="EPS";

//trimming
std::string trim(const std::string& str,
				const std::string& whitespace = " \t\n")
{
		const auto int strBegin = str.find_first_not_of(whitespace);
		if (strBegin == std::string::npos)
				return ""; // no content

		const auto int strEnd = str.find_last_not_of(whitespace);
		const auto int strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
}


vector <string> splitstr(string message){
		message = trim(message);
        stringstream ss(message);
		string s;
		vector <string> str;
		while(ss>>s){
				//cout<<s<<endl;
				str.push_back(s);
		}
		return str;
}


queue <string> splitstr_queue(string message){
    stringstream ss(message);
    string s;
    queue <string> str;
    while(ss>>s){
        //cout<<s<<endl;
        str.push(s);
    }
    return str;
}

stack <string> splitstr_stack(string message){
    stringstream ss(message);
    string s;
    stack <string> str;
    while(ss>>s){
        //cout<<s<<endl;
        str.push(s);
    }
    return str;
}

/* Generate name for the new NonTerminal. */
string
Grammar::generateName (string nt) {
	static int number = 0;
	string newName = "__"+nt+numToString (number)+"__";
	return newName;
}

/* Remove direct left recursion. */
void
Grammar::removeDirectLeftRecursion (string nt, vector<string> &p, vector<NonTerminal> &vnewnt, vector<string> &snewnt) {
	vector<bool> left_club(p.size (), false);
	set<string> to_add;
	set<string>::iterator it;

	string newnt;
	bool generated=false;

	// which are to be clubbed for the new NonTerminal
	// START DEALING WITH OLD NONTERMINAL
	for (int i=0; i<p.size (); i++) {
		vector<string> tokens = splitstr (p[i]);
		if ((tokens.size () > 0) && (tokens[0] == nt)) {
			if (!generated) {
				// Otherwise need to generate a new NonTerminal
				newnt = generateName (nt);
				generated = true;
			}
			left_club[i] = true;
			string left_p = p[i].substr (nt.length ());
			left_p = trim (left_p);
			to_add.insert (left_p+" "+newnt);
		}
	}

	// check if there is any need to generate a new NonTerminal
	if (find (left_club.begin (), left_club.end (), true) == left_club.end ())
		return ;		// no new non terminal

	// bA' type
	for (int i=0; i<p.size (); i++) 
		if (!left_club[i]) p[i] += " " + newnt;

	set<string> new_rules (p.begin (), p.end ());
	set<string> old_rules;
	for (int i=0; i<p.size (); i++) 
		if (left_club[i]) old_rules.insert (p[i]);

	/* @Ak2
	 * GREATEST MISTAKES OF CODING LIFE.
	 * new_rules.erase (old_rules.begin (), old_rules.end ());
	 */
	for (it=old_rules.begin (); it != old_rules.end (); it++)
		new_rules.erase (*it);

	p.clear ();
	for (it=new_rules.begin (); it != new_rules.end (); it++)
		p.push_back (*it);
	// END DEALING WITH OLD NONTERMINAL

	// ADD NEW NONTERMINAL
	// Add new productions in a new NonTerminal
	NonTerminal NT;
	for (it=to_add.begin (); it != to_add.end (); it++)
		NT.productions.push_back (*it);

	NT.productions.push_back (EPSILON);
	NT.nullable = true;

//	nonTerminals[newnt] = NT;
	vnewnt.push_back (NT);
	snewnt.push_back (newnt);
}

/* Remove indirect left recursion. */
void
Grammar::removeIndirectLeftRecursion () {
	vector<NonTerminal> vnt, vnewnt;
	vector<string>	snt, snewnt;
	map<string, NonTerminal>::iterator out;

	for (out=nonTerminals.begin (); out!=nonTerminals.end (); out++) {
		snt.push_back (out->first);
		vnt.push_back (out->second);
	}

	//cout << "Removing indirect left recusion " << endl;

	for (int i=0; i<vnt.size (); i++) {
		//cout << "NT " << snt[i] << endl;
		vector<string> &productions = vnt[i].productions;
		for (int j=0; j<i; j++) {
			//cout << "\t searching for " << snt[j] << endl;
			for (int k=0; k<productions.size (); k++) {
				vector<string> to_add;

				//cout << "in production " << productions[k] << endl;
				string nt = snt[j];
				vector<string> tokens = splitstr (productions[k]);
				if (tokens.size ()>0 && (tokens[0] == nt)) {
					//cout << "it in production " << productions[k] << endl;
					string left_token = productions[k].substr (nt.length ());
					vector<string> &from = vnt[j].productions;
					// replace the ith by the 1st rule here & place the remaining at the end instead of erasing this element
					if (from.size () > 0)
						productions[k] = from[0] + " " + left_token;

					for (int p=1; p<from.size (); p++)
						to_add.push_back (from[p]+" "+left_token);

					// add these rules to the productions & remove the
					// current one
				}
				productions.insert (productions.end (), to_add.begin (), to_add.end ());
			}
		}
		// Remove direct recursion for each production in the vector
		removeDirectLeftRecursion (snt[i], vnt[i].productions, vnewnt, snewnt);
	}

	//cout << "Start of new non terminals " << endl;
	//for (int i=0; i<vnewnt.size (); i++) {
		//cout << snewnt[i] << "-->" << endl;
		//for (int j=0; j<vnewnt[i].productions.size (); j++) 
		//cout << vnewnt[i].productions[j] << endl;
		//cout << endl;
	//}
	//cout << "End of new non terminals " << endl;

	vnt.insert (vnt.end (), vnewnt.begin (), vnewnt.end ());
	snt.insert (snt.end (), snewnt.begin (), snewnt.end ());

	for (int i=0; i<vnt.size (); i++) nonTerminals[snt[i]] = vnt[i];
}

string
concatString (string a, string b) {
	return a + " " + b; 
}

/* Calculate the follow sets of the NonTerminals */
void
Grammar::populateFollow () {
	// add dollar to the followSet of start symbol
	if (!isNonTerminal (start)) {
		cout << "Error Follow:No start non-terminal symbol in the grammar"
			 << endl;
		exit (EXIT_FAILURE);
	}

	nonTerminals[start].followSet.insert (dollar);

	map<string, NonTerminal>::iterator it;
	while (1) {
        cout<<"In While" <<endl;
	bool change = false;
	for (it=nonTerminals.begin (); it!=nonTerminals.end (); it++) {
		vector<string> P = it->second.productions;
		for (int i=0; i<P.size (); i++) {
			stringstream ss (P[i]);
			string nt, reverse_pi;
			vector<string> tokens = splitstr (P[i]);

			// P[i]->x1 x2 x3.. xn
			// 1 to n-1, although it'll go till n but the nth first will be empty
			for (int i=0; i<tokens.size ()-1; i++) {
				nt = tokens[i];
                		if (isNonTerminal (nt)) {
					// TODO NEW CODE TO BE TESTED,-1
					string next = accumulate (tokens.begin ()+i+1, tokens.end (), string(""), concatString);
					next = trim (next);
					//cout << "i+1 to n " << next << endl;
					set<string> f_next = firstOf (next);
					f_next.erase (EPSILON);
					// TODO

					set<string> &follow = nonTerminals[nt].followSet;
					bool subset = includes (follow.begin (), follow.end (),
								f_next.begin (), f_next.end ());
					if (!subset) {
					//	cout << next <<" is subset " << " of " << nt << endl;
						follow.insert (f_next.begin (), f_next.end ());
						//change |= subset;
						change = true;
					}
				}
			}
		
			// TODO delete the last space	
			// n to 1
			for (int i=tokens.size ()-1; i>=0; i--) {
				nt = tokens[i];
				// TODO NEW CODE TO BE TESTED, -1
				string next = accumulate (tokens.begin ()+i+1, tokens.end (), string(""), concatString);
				next = trim (next);
				//cout << "i+1 to n " << next << endl;
				// TODO

				if (isNonTerminal (nt) && nullable (next)) {
				//	cout << "next is nullable " << next << endl;
					set<string> followPI = it->second.followSet;	// follow set of the current NT
					set<string> &follow = nonTerminals[nt].followSet;
					bool subset = includes (follow.begin (), follow.end (),
								followPI.begin (), followPI.end ());
					if (!subset) {
				//		cout << next <<" is subset " << " of " << nt << endl;
						follow.insert (followPI.begin (), followPI.end ());
						//change |= subset;
						change = true;
					}
				}
			}
		}
	}

	// if no change in any follow set, break the while loop
	if (!change) break;
	}
}

/* Calculates the Nullability of a production. */
bool 
Grammar::nullable (string P) {
	if (P == "" || P == EPSILON) return true;

	stringstream ss (P);
	string nt;
	ss >> nt;
	// TODO check for trailing whitespaces in the ss stream
	if (isTerminal (nt)) return false;
	else if (isNonTerminal (nt) && !nonTerminals[nt].nullable) return false;
	else {
		// TODO NEW CODE TO BE TESTED
		string to_check = ss.str ().substr (nt.length ());
		to_check = trim (to_check);
		return nullable (to_check);
		// TODO
	}
}

/* Calculates the First set of a production.
 * Recursion shouldn't be the bottolneck
 */
set<string> 
Grammar::firstOf (string production) {
	//stringstream ss (production);
	string nt;
	set<string> first;

	production = trim (production);
	vector<string> tokens = splitstr (production);

	if (tokens.empty ()) return first;

	nt = tokens[0];
	if (nt != "") {
		if (isTerminal (nt)) first.insert (nt);
		else {
			bool isNt = isNonTerminal (nt);
			if (!isNt) {
                		cout <<"Terminal "<< nt <<endl;
				cout << "Error firstOf: Symbol not in the grammar"
					<< endl;
				exit (EXIT_FAILURE);
			}

			if (isNt && !nonTerminals[nt].nullable)
				return nonTerminals[nt].firstSet;

			first.insert (nonTerminals[nt].firstSet.begin (),
					nonTerminals[nt].firstSet.end ());

			// TODO NEW CODE TO BE TESTED
			//string to_check = ss.str ().substr (nt.length ());
			//trim (to_check);

			string next, back;
			substr_token (production, 1, back, next);
			set<string> f_next = firstOf (next);
			// TODO

			first.insert ( f_next.begin (), f_next.end ());
		}
	}

	return first;
}

//Tokenised, space separated input is assumed
//eg: Id plus whitespace etc
void Grammar::parse(string input){
	cout <<"input: "<< input <<endl;
    queue<string> q = splitstr_queue(input);
	stack<string> s;

	q.push(dollar);
	s.push(dollar);
    s.push(start);
    cout<< "Parsing Stack: " <<endl; 
	while( !(s.empty() && q.empty()) ){ // Terminals matched and removed
        cout << s.top() <<endl;
        if(s.top() == q.front()){
			s.pop();
			q.pop();
		} 
		else if( nonTerminals.find(s.top()) != nonTerminals.end() ){ // Stack has Nonterminal
			if(!isTerminal(q.front())){
			    printf("Error occured in parsing input file: %s\n",q.front ().c_str ());
			    return;
            }
            string prod = nonTerminals[s.top ()].parseTable[q.front()];
			stack<string> stk = splitstr_stack(prod);

			s.pop();
			if(stk.top() != EPSILON){ // if prod is epsilon, then just pop
				while(!stk.empty()){
					s.push(stk.top());
					stk.pop();
				}
			}
		}
		else{ // error
			printf("Error occured in parsing input file: %s\n",q.front ().c_str ());
			return;
		}
	}
}

void Grammar::makeParse(){
	//set<string> first = firstOf();
	map<string,NonTerminal>::iterator it;
	for(it=nonTerminals.begin(); it != nonTerminals.end() ; it++){
		NonTerminal &tmp = it->second;
        //single nontreminal
		for(int i=0;i<tmp.productions.size();i++){
			string prod = tmp.productions[i];
            //cout << "parse table: prod:  "<<prod <<endl;
			set<string> first = firstOf(prod);
			set<string>::iterator it_set;
			bool eps_in = false;
			for(it_set = first.begin(); it_set != first.end() ; it_set++){
				string terminal = *it_set;
                //cout << "parse table: terminal:  "<<terminal <<endl;
				//if epsilon
				if(terminal == EPSILON){
					eps_in = true;
				}
                else
				tmp.parseTable[terminal] = prod;
			}

			if(eps_in){ // also calculate from follow set
				set<string> follow = tmp.followSet;
				for(it_set = follow.begin(); it_set != follow.end() ; it_set++){
					//string terminal = *it_set;   
					tmp.parseTable[*it_set] = prod;
				}
			}
		}

	}
}

void Grammar::calcNullable(){
		bool change = false;
		while(1){
				if(change){
						change = false;
				}
				else break;

				map<string,NonTerminal>::iterator it;
				for(it=nonTerminals.begin(); it != nonTerminals.end() ; it++){
						NonTerminal tmp = it->second;
						if(tmp.nullable)
								continue;

						bool non_terminal_nullable = false;

						//single nontreminal
						for(int i=0;i<tmp.productions.size();i++){
								vector<string> v = splitstr(tmp.productions[i]);
								bool all_nullable = true;

								//single production, if any one of the production is all_nullable, the nonTerminal is nullable
								for(int j=0;j<v.size();j++){
										if(nonTerminals.find(v[j])!=nonTerminals.end()){
												if(!nonTerminals[v[j]].nullable){
														all_nullable = false;
														break;
												}
										} 
										else{
												all_nullable = false;
												break;
										}
								}

								if(all_nullable){
										non_terminal_nullable = true;
										break;
								}
						}

						if(non_terminal_nullable){
								tmp.nullable = true;
								change = true;
						}

				}
		}
}

Grammar::Grammar(string fileName){
		string data;
		ifstream file(fileName.c_str(),ifstream::in);
		if(!file.is_open()){
				cout << "Error Opening file";
				exit(EXIT_FAILURE);
		}

		getline(file,data);
		while(!file.eof() && data != "%%"){
			if(!file.eof() && data != "%%" && data != ""){
				if(data[0] != '%'){
						cout << "Error in Syntex of Grammar\n";
							exit(EXIT_FAILURE);
						}

						vector<string> all_token = splitstr(data);
						/*
						   %token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
						   %start translation_unit
						 */

						if(all_token[0] == "%token"){
								if(all_token.size() > 1)
										terminals.insert(all_token.begin()+1,all_token.end());
						}
						else if(all_token[0] == "%start"){
								if(all_token.size() > 1)
										start = all_token[1];
						}
						//			cout << " Terminals " << data << endl;
				}
				getline(file,data);
		}
		while(!file.eof() ){
				getline(file,data);
				data = trim(data);
				if(data == "")
					continue;
				NonTerminal nt;
				set<string> tmp;
				nt.nullable = false;
				string nonTerminalName = "";

				while(!file.eof() && data != ";"){
						if(!file.eof() && data != ";" && data != "") {
								if(data[0] != ':' && data[0] != '|'){
										nonTerminalName = data;
										//If non terminal in not in map
										if(isNonTerminal(nonTerminalName)){
												nt = nonTerminals[nonTerminalName];
										}
										//					cout <<"Token : "<< data<<endl ;
								}
								else{
										// Rules are of the form
										// \t: primary_expression
										data = data.substr(1);
										data = trim(data);
										if(data == ""){
											cout << "Error : empty productions\n";
											exit(EXIT_FAILURE);
										}
										tmp.insert(data);
										if(data == EPSILON)
											nt.nullable = true;

										//					cout <<"Rules :" << data << endl;
								}
						}
						getline(file,data);
						data = trim(data);
				}
				if(!file.eof()){
					nt.productions.insert(nt.productions.begin(),tmp.begin(),tmp.end());	
					nonTerminals[nonTerminalName] = nt;
					
				}

		}

        printTerminals();

	cout << "Before removing left recursion " <<  endl;
	printProductions ();
	removeIndirectLeftRecursion ();
	//leftFactor();
    	cout << "After removing left recursion " <<  endl;
	printProductions ();
	
	calcNullable ();
	populateFirst();
	populateFollow();
	makeParse(); 
}

/*
   Algorithm

   For each terminal t
   First(t) = { t }
   For each non-terminal N
   First(N) = { } 
   Repeat
   For each production N ::= x1x2x3…xn
   First(N) = First(N) ∪ First(x1)
   For each i from 2 through n
   If Nullable(x1…xi-1), then
   First(N) = First(N) ∪ First(xi)
   Until no First set changes

 */

void Grammar::populateFirst(){
		map<string, NonTerminal>::iterator it;
		vector<string>::iterator vit;
		bool isChanged = true;
		while(isChanged){
				//cout << "In populateFirst"<< endl;
				isChanged = false;
				for (it=nonTerminals.begin(); it!=nonTerminals.end(); ++it){
						NonTerminal &nt = it->second;
						//For each production
						for(vit=nt.productions.begin();vit!=nt.productions.end();vit++){
								vector<string> alphabet = splitstr(*vit);
								if(addFirst(nt,alphabet[0]))
										isChanged = true;

								for(int i=1;i<alphabet.size();i++){
										string sub_prod = "";
										for(int j=0;j<i;j++){
											sub_prod += alphabet[j];
											sub_prod += ' ';	
										}
										//cout <<" sub_prod : " <<sub_prod <<endl;
										if(nullable(sub_prod)){
											//cout << "Nullable : " <<sub_prod << endl;
												if(addFirst(nt,alphabet[i]))
														isChanged = true;
										}
								}
						}

				}
		}
}

/*
   If str is a nonTerminal then adds FIRST[str] to that of nt
   If str is a Terminal then adds it to the first set
   Returns true is there has been change in the first set
 */ 
bool
Grammar::addFirst(NonTerminal &nt,string str){
		if(isNonTerminal(str)){
				if( includes (nt.firstSet.begin (), nt.firstSet.end (), 
										nonTerminals[str].firstSet.begin (), nonTerminals[str].firstSet.end () ) )
						return false;
				set<string> first = nonTerminals[str].firstSet;
				nt.firstSet.insert(first.begin (), first.end ());
		}
		else if (isTerminal(str)){
				if(nt.firstSet.find(str) != nt.firstSet.end())
						return false;
				nt.firstSet.insert(str);
		}else{
				cout << "Cannot identify the string : "<<str<<endl;
				exit(EXIT_FAILURE);	
		}
		return true;
}

void Grammar::printProductions () {
		map<string,NonTerminal>::iterator it;
		//cout << "size in nonterm of non ter " << nonTerminals.size () << endl;
		cout << "Productions : "<<endl;
		for(it=nonTerminals.begin() ; it!= nonTerminals.end() ; it++){
				cout << it->first << " - >" << endl;
				vector<string> p = it->second.productions;
				for (int i=0; i<p.size (); i++) 
					cout << p[i] << endl;

			cout << endl;
		}
}

void Grammar::printNonTerminals(){
		map<string,NonTerminal>::iterator it;
		//cout << "size in nonterm of non ter " << nonTerminals.size () << endl;
		cout << "Grammer : ";
		for(it=nonTerminals.begin() ; it!= nonTerminals.end() ; it++){
				cout << "NT "<<it->first << " " << endl;
		        vector<string> prod = (it->second).productions;
                for(int i=0;i<prod.size();i++)
                    cout<< prod[i] <<"      ";
                cout<<endl;
        }
}

void Grammar::printTerminals(){
		set<string>::iterator it;
		cout << "Terminals : ";
		for ( it = terminals.begin() ; it != terminals.end() ; it++){
				cout << *it << ' ';
		}
		cout << endl;
}

void Grammar::printFirstSet(){
		map<string,NonTerminal>::iterator it;
		//cout << "size in first of non ter " << nonTerminals.size () << endl;
		for(it=nonTerminals.begin() ; it!= nonTerminals.end() ; it++){
				cout << it->first <<endl;
				set<string> first_set = (it->second).firstSet;
				set<string>::iterator it_set;
				cout << "First Set : ";
				for ( it_set = first_set.begin() ; it_set != first_set.end() ; it_set++){
						cout << *it_set << ' ';
				}
				cout << endl;

		}
}

void Grammar::printFollowSet(){
		map<string,NonTerminal>::iterator it;
		for(it=nonTerminals.begin() ; it!= nonTerminals.end() ; it++){
				cout << it->first <<endl;
				set<string> fset = (it->second).followSet;
				set<string>::iterator it_set;
				cout << "Follow Set : ";
				for ( it_set = fset.begin() ; it_set != fset.end() ; it_set++){
						cout << *it_set << ' ';
				}
				cout << endl;

		}
}

void Grammar::printParseTable(){
		map<string,NonTerminal>::iterator it;
		for(it=nonTerminals.begin() ; it!= nonTerminals.end() ; it++){
				cout << it->first <<endl;
				map<string,string> pt = (it->second).parseTable;
				map<string,string>::iterator it_mp;
				cout << "Parse Table : " <<endl;
				for ( it_mp = pt.begin() ; it_mp != pt.end() ; it_mp++){
						cout << it_mp->first << " : " <<it_mp->second << endl;
				}
				cout << endl;

		}
}

int how_many_match(string s,string t){
    vector<string> t1 = splitstr(s);
    vector<string> t2 = splitstr(t);
    int count = 0;
    for(int i=0; i<t1.size() && i<t2.size() ; i++){
        if(t1[i]==t2[i]) count++;
        else return count;
    } 
}

void
Grammar::substr_token(string s,int front_tokens,string &front,string &back){
    vector<string> t1 = splitstr(s);
    vector<string> s1(t1.begin(),t1.begin()+front_tokens);
    vector<string> s2(t1.begin()+front_tokens,t1.end());
    
    for(int i=0;i<s1.size();i++) front += s1[i] + " ";
    for(int i=0;i<s2.size();i++) back += s2[i] + " ";
    
    front = trim(front);
    back = trim(back);
}

void
Grammar::leftFactor(){
    map<string,NonTerminal> total_nt_map = nonTerminals;
    map<string,NonTerminal> new_nt_map;

    cout<<"left Factor"<<endl;
    while(1){
    
        map<string,NonTerminal>::iterator it;
	    for(it=total_nt_map.begin() ; it!= total_nt_map.end() ; it++){
		    NonTerminal nt = it->second;
            vector<string> prod = nt.productions;
            vector<string> new_prod;
            sort(prod.begin(),prod.end());
            for(int i=0; i < prod.size();){
                
                int val = -1;
                int j;
                int count;

                for(j=i+1;j<prod.size();j++){
                    count = how_many_match(prod[j-1],prod[j]);
                    if(count == 0) {
                        break;
                    }
                    else if(val == -1) val = count;
                    else { // to check for more then a pair
                        if(count < val) break;
                    }
                } 
              
                if(j-i == 1){ // unique production, continue 
                    new_prod.push_back(prod[i]);
                }
                // j is the first non matched index with i (j may also exceed size of prod)
                if( j-i > 1 ){ // something matched
                            
                    //1. Remove all common prod
                    //2. Add new prod 'common __NT_i'
                    //3. Add one NT as '__NT_i'
                    //4. Add new prods in new NT
                   
                    string front,back;
                    substr_token(prod[i],count,front,back);
                    string new_nt_name = generateName(it->first);
                
                    // 2    
                    new_prod.push_back(front+" "+new_nt_name);
                
                    NonTerminal new_nt;
                    // 1 & 4
                    for(int k=i;k<j;k++){ // Make new NT and change the current productions
                        string start,end;
                        substr_token(prod[k],count,start,end);
                        //new_nt.addProductions(end);
                        new_nt.productions.push_back(end);
                    }
                
                    // 3
                    new_nt_map[new_nt_name] = new_nt;
                }
                i = j;
            }

            (it->second).productions = new_prod;
        }
   
        // Break Condition
        if(new_nt_map.empty())break;
        else{ // TODO: add new_nt_map to total_nt_map
           total_nt_map.insert(new_nt_map.begin(),new_nt_map.end());
           new_nt_map.clear();
        }
    }
    nonTerminals = total_nt_map;
}
