#include "ll1_parser.h"

using namespace std;

/* $ symbol */
const string dollar="DOLLAR";
const string EPSILON="EPS";

vector <string> splitstr(string message){
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

	map<string, NonTerminal> it;
	while (1) {
	bool change = false;
	for (it=nonTerminals.begin (); it!=nonTerminals.end (); it++) {
		vector<string> P = it->second->productions;
		for (int i=0; i<P.size (); i++) {
			stringstream ss (P[i]);
			string nt, reverse_pi;

			// P[i]->x1 x2 x3.. xn
			// 1 to n-1, although it'll go till n but the nth first will be empty
			while (ss >> nt) {
				reverse_pi += nt + " ";
				if (isNonTerminal (nt)) {
					set<string> f_next = firstOf (ss.str ());
					bool inserted = NonTerminal[nt].followSet.insert (f_next.begin (), f_next.end ()).second;
					change |= inserted;
				}
			}
		
			// TODO delete the last space	
			// n to 1
			ss.str (reverse_pi);
			while (ss >> nt) {
				if (isNonTerminal (nt) && nullable (ss.str ())) {
					set<string> followPI = it->followSet;	// follow set of the current NT
					bool inserted = NonTerminal[nt].followSet.insert (followPI.begin (), followPI.end ()).second;
					change |= inserted;
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
	if (isNonTerminal (nt) && !nonTerminals[nt].nullable) return false;
	else return nullable (ss.str ());
}

/* Calculates the First set of a production.
 * Recursion shouldn't be the bottolneck
 */
set<string> &
Grammar::firstOf (string production) {
	stringstream ss (production);
	string nt;
	set<string> first;

	ss >> nt;
	if (nt != "") {
		if (isTerminal (nt)) {
			first.insert (nt);
			break;
		}

		bool isNt = isNonTerminal (nt);
		if (!isNt) {
			cout << "Error firstOf: Symbol not in the grammar"
				<< endl;
			exit (EXIT_FAILURE);
		}

		if (isNt && !nonTerminals[nt].nullable)
			return nonTerminals[nt].firstSet;

		first.insert (nonTerminals[nt].firstSet.begin (),
				nonTerminals[nt].firstSet.end ());
		set<string> f_next = firstOf (ss.str ());
		first.insert ( f_next.begin (), f_next.end ());
	}

	return first;
}

//Tokenised, space separated input is assumed
//eg: Id plus whitespace etc
void Grammer::parse(string input){
    queue<string> q = splitstr_queue(input);
    stack<string> s;

    q.push(dollar);
    s.push(dollar);

    while( !(s.empty() && q.empty()) ){ // Terminals matched and removed
       if(s.top() == q.front()){
            s.pop();
            q.pop();
       } 
       else if( nonTerminals.find(s.top()) != nonTerminals.end() ){ // Stack has Nonterminal
                string prod = nonTerminals[s.top].parseTable[q.front()];
                stack<string> stk = splitstr_stack(prod);
                
                s.pop();
                if(stk.top() != "EPS"){ // if prod is epsilon, then just pop
                    while(!stk.empty()){
                        s.push(stk.top());
                        stk.pop();
                    }
                }
       }
       else{ // error
            printf("Error occured in parsing input file: %s\n",q.front())
            return;
       }
    }
}

void Grammer::makeParse(){
   
    //set<string> first = firstOf();
    map<string,NonTerminal>::iterator it;
    for(it=NonTerminals.begin(); it != nonTerminals.end() ; it++){
        NonTerminal tmp = it->second;
           //single nontreminal
        for(int i=0;i<tmp.productions.size();i++){
            string prod = tmp.productions[i];
            set<string> first = firstOf(prod);
            set<string>::iterator it_set;
            bool eps_in = false;
            for(it_set = first.begin(); it_set != first.end() ; it_set++){
                string terminal = *it_set;
                
                //if epsilon
                if(s == EPSILON){
                    eps_in = true;
                }

                map[terminal] = prod
            }

            if(eps_in){ // also calculate from follow set
                set<string> follow = tmp.followSet;
                for(it_set = follow.begin(); it_set != follow.end() ; it_set++){
                    //string terminal = *it_set;   
                    map[*it_set] = prod
                }
            }
        }

    }
}

void Grammer::calcNullable(){

    bool change = false;
    while(1){
        if(change){
            change = false;
        }
        else break;

        map<string,NonTerminal>::iterator it;
        for(it=NonTerminals.begin(); it != nonTerminals.end() ; it++){
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

void Grammar(char * fileName){
	
	string data;
	ifstream file(fileName,ifstream::in);
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
//			cout << data << endl;
		}
		getline(file,data);
	}
	while(!file.eof()){
		getline(file,data);

		NonTerminal nt;

		string nonTerminalName = "";

		while(!file.eof() && data != "\t;"){

			if(!file.eof() && data != "\t;" && data != "") {

				if(data[0] != '\t'){
					nonTerminalName = data;
					
					//If non terminal in not in map
					if(isNonTerminal(nonTerminalName)){
						nt = nonTerminals[nonTerminalName];
					}
					cout <<"Token : "<< data<<endl ;
				}

				else{
					// Rules are of the form
					// \t: primary_expression
					data = data.substr(3);
					nt.production.push_back(data);

					if(data == EPSILON)
						nt.nullable = true;

					cout <<"Rules :" << data << endl;
				}
			}
			getline(file,data);
		}

		nonTerminals[nonTerminalName] = nt;
	}



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
		cout << "In populateFirst"<< endl;
		isChanged = false;
		for (it=nonTerminals.begin(); it!=nonTerminals.end(); ++it){
			NonTerminal nt = it->seecond;
			//For each production
			for(vit=nt.productions.begin();vit!=nt.productions.end();vit++){
				vector<string> alphabet = splitstr(nt.second);
				if(addFirst(nt,alphabet[0]))
					isChanged = true;

				for(int i=1;i<alphabet.size();i++){
					string sub_prod = "";
					for(int j=0;j<i;j++)
						sub_prod += alphabet[j];
					if(nullable(sub_prod)){
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
Grammar::addFirst(NonTerminal nt,string str){
	if(isNonTerminal(str)){
		if(includes(nt.firstSet.begin(),nt.firstSet.end();map[str].firstSet.begin(),map[str].firstSet.end()))
			return false;
		nt.firstSet.insert(map[str].firstSet);
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
