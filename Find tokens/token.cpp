/*
	               _            .                                 .x+=:.
	              u            @88>                              z`    ^%    .uef^"
	             88Nu.   u.    %8P      u.    u.                    .   <k :d88E
	      u     '88888.o888c    .     x@88k u@88c.       u        .@8Ned8" `888E
	   us888u.   ^8888  8888  .@88u  ^"8888""8888"    us888u.   .@^%8888"   888E .z8k
	.@88 "8888"   8888  8888 ''888E`   8888  888R  .@88 "8888" x88:  `)8b.  888E~?888L
	9888  9888    8888  8888   888E    8888  888R  9888  9888  8888N=*8888  888E  888E
	9888  9888    8888  8888   888E    8888  888R  9888  9888   %8"    R88  888E  888E
	9888  9888   .8888b.888P   888E    8888  888R  9888  9888    @8Wou 9%   888E  888E
	9888  9888    ^Y8888*""    888&   "*88*" 8888" 9888  9888  .888888P`    888E  888E
	"888*""888"     `Y"        R888"    ""   'Y"   "888*""888" `   ^"F     m888N= 888>
	 ^Y"   ^Y'                  ""                  ^Y"   ^Y'               `Y"   888
	                                                                             J88"
	                                                                             @%
	                                                                           :"
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FINAL_STATE_SZ 1

const int MAXN = 100;

ifstream Table, inp;

int current_state;
int final_states[FINAL_STATE_SZ] = { 99 };
int table[MAXN][256];
string accepted_characters = " ;()<>[]abcdefghijklmnopqrstuvwxyz";
int ACCEPTED_CHAR_SZ;
vector<string> words;

vector<string> parse(string s) {
	stringstream ss(s);
	
	do{
		string tmp;
		ss >> tmp;
		words.push_back(tmp);
	} while(ss);
	
	return words;
}
 
int toDec(string n){
	int res = 0;
	for(int i=0;i<n.size();++i) {
		res = res*10 + n[i]-'0';
	}
	return res;
}

void transition_table() {
	Table.open("inp.txt");
	string s;
	int x, y;
	fill(&table[0][0], &table[MAXN][0], 10);
	
	while(getline(Table, s) ) {
		if(s.empty()) continue;
		
		words.clear();
		words = parse(s);
		
		x = toDec(words[0]);
		y = toDec(words[2]);
		if(words[1] == "32") table[x][32] = y;
		else table[x][int(words[1][0])] = y;
	}		
}

int DFA(char c) {
	int flag = 0;
	if(current_state == 55 && (c == '\0' || c == '\n')) {
		current_state = 99;
		return current_state;
	}
	for(int i = 0; i< accepted_characters.size(); ++i)
		if(c == accepted_characters[i]) { flag = 1; break; }

	if(!flag) current_state = 0;

	else
	current_state = table[current_state][c];
	
	return current_state;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	transition_table();

	string s;
	int flag, curr_ptr, prev_ptr, state; 
	ACCEPTED_CHAR_SZ = accepted_characters.size();
	inp.open("file.txt");
	if(!inp.is_open()) cout<<"error";
	current_state = 0;
	
	while(getline(inp, s)) {
		curr_ptr = prev_ptr = 0;
		for(int i=0; s[i]; ++i) {
			state = DFA(s[i]); 
			if(state == 99) {
				for(int l=prev_ptr ;l<curr_ptr; ++l) cout<<s[l];
				cout<<endl;
				prev_ptr = i+1;
				current_state = 0;
			}
			if(state == 0) prev_ptr = i;
			curr_ptr++;
		}
	
	}

}
