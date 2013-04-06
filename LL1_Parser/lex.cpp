#include "declarations.h"
#include <fstream>
#define BUF_SIZE 1024

string sanitize(string regex) {
	regex = regex.substr(1,regex.length()-2);
	string ret="";
	for(int i=0; i < regex.length(); i++) {
		if (regex[i] == '$') {
			ret += ' ';
		}
		else if(regex[i]=='\\') {
			if (i+1 == regex.length ()) break;
			switch(regex[i+1]){
				case 't':
					ret += '\t';
					i++;
					break;
				case 'n':
					ret += '\n';
					i++;
					break;
				default:
					ret += regex[i];
			}
		}
		else{
			ret += regex[i];
		}
	} 
	return ret;
}

string get_file_contents(const char *filename)
{
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
}

void lex() {

	//cout<<"Input filename: "<<endl;
	string filename = "input_regex.txt";
	//   cin>>filename;

	ifstream fpi(filename.c_str ());
	if(!fpi){
		cout<<"Error in Openeing File: "<< filename<<endl;
		exit(EXIT_FAILURE);
	}

	vector<string> token_class;
	vector<string> regex;
	string token_class_buf,regex_buf;

	while(!fpi.eof() && fpi>>token_class_buf && fpi>>regex_buf) {
		/*           cout<< "class: " << token_class_buf
			     << " regex: " << regex_buf ;
			     cout <<" BEFORE" << endl; */
		token_class.push_back(token_class_buf);
		regex_buf = sanitize(regex_buf);
		regex.push_back(regex_buf);

		//cout<< "class: " << token_class_buf
		//	<< " regex: " << regex_buf ;
		//cout <<" DONE" << endl;
	}
	//    exit(EXIT_FAILURE);

	vector<dfa> dfas;

	for(int i=0 ; i< regex.size(); i++){
		nfa n(regex[i]);
		dfas.push_back(n.to_dfa());    
		//dfas[i].print_transitions ();
		//dfas[i].print_final();
		//cout<<endl;
	}

/*	cout<<" Write the index of the regex corresponding to Identifiers class (0 based index) : "<<endl;
	int id_class;
	cin >> id_class;

	while(id_class < 0 || id_class >= regex.size()){
		cout<< "Invalid Id class !! , please write again"<<endl;
		//exit(EXIT_FAILURE);
		cin >> id_class;
	}
*/
	ofstream of("lex_output.txt");



	//symbol table
	vector< vector<string> > symbol_table(regex.size());

	//d.print_transitions ();
	cout<<"Give input file name: "<<endl;
	string input_file;
	cin >> input_file;
	string input = get_file_contents(input_file.c_str());

	int current=0;

	// MAXIMAL MUNCH IMPLEMENTED
	while(current < input.length()){

		for(int i=0; i<dfas.size(); i++){
			dfas[i].reset();
		}
		vector<string> buffer(dfas.size());
		vector<int> max_num_chars_to_final(dfas.size(),-1);

		/*
		//If dfa i accepts the string then final state is stored in 
		//this vector and -1 otherwise
		vector<int> dfa_accept(dfas.size(),-1);
		 */
		int max_advance = -1;
		for(int j=0;j < dfas.size() ; j++){
			//Do not advance if the next state is rejecting
			for(int i =0; current+i < input.length() ;i++){

				if(dfas[j].peek_rejecting(input[current+i]))
					break;

				dfas[j].advance(input[current+i]); 
				if(dfas[j].final[dfas[j].current_state]){
					max_num_chars_to_final[j] = i+1;
					//            cout<<"j: "<<j<<" "<<i<<endl;
				}
			}
			if(max_num_chars_to_final[j] > max_advance) max_advance = max_num_chars_to_final[j];
			//  cout << max_num_chars_to_final[j] <<endl ;
		}

		if(max_advance == -1 || max_advance == 0) {
			cout << "Error in lexical Analysis: No dfa accepted it" <<endl; 
			exit(1);
		}

		int accepting_dfa = -1;
		for(int j=0;j < dfas.size() ; j++){
			if(max_num_chars_to_final[j] == max_advance){
				accepting_dfa = j;
				break;
			}
		}

		string output = input.substr(current,max_advance);
		symbol_table[accepting_dfa].push_back(output);
		//string output(input[current],input[current+max_advance]);
		//cout << "< "<<token_class[accepting_dfa] <<" , "<<output<<" >" << endl;
	//	cout<<output<<endl;
		if (output == "\n") of << endl;
		else if(output != "\t" && output != " ") 
			of <<token_class[accepting_dfa]<< " ";

		current += max_advance;

		/* -1 -> next is rejecting && present is not final
		 *  0 -> " && present is final
		 */
	}
	/*
	   cout<<"Symbol Table: "<<endl;
	   for(int i=0; i<symbol_table[id_class].size(); i++){
	   cout<<i<<" "<<symbol_table[id_class][i]<<endl;
	   }
	 */
	of.close();

}
