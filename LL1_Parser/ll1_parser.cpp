#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "llq_parser.h"

using namespace std;

vector<string> splitstr(string message){
    stringstream ss(message);
    string s;
    vector <string> str;
    while(ss>>s){
        //cout<<s<<endl;
        str.push_back(s);
    }
    return str;
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
					
					if(data == "EPS")
						nt.nullable = true;

					cout <<"Rules :" << data << endl;
				}
			}
			getline(file,data);
		}

		nonTerminals[nonTerminalName] = nt;
	}



}

