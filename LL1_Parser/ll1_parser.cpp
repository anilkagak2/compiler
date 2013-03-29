#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

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



/* Class representing the abstract notion of NonTerminals */
class NonTerminal {
    public:
        NonTerminal (string p);
        ~ NonTerminal ();
        void addProductions (string p);

        bool nullable;
        set<string> 		firstSet;
        set<string> 		followSet;
        map<string, string>	parseTable;
        vector<string>		productions;
};


/* Class representing the abstract notion of Grammars
 * (Terminals, Non-Terminals, StartSymbol, Productions)
 */
class Grammar {
    public:

    private:
        map<string, NonTerminal> nonTerminals;
        set<string>		 terminals;
        void calcNullable();
        void populateFirst();
        void populateFollow();
        void makeParse();
};

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
                if(s == "EPS"){
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
