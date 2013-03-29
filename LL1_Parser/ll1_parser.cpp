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
