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
#include <bits/stdc++.h>
using namespace std;
#define mset(a,o) memset((a),(o),sizeof(a))
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define caset int __T,case_n=1;scanf("%d",&(__T));while(__T--)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

#define oo 0x3f3f3f3f
const int mod = 1000000007;
const int MAXN = 100000+9;
/*=======================================================================================================*/

char startSymbol;
vector<string> Prule;
map<char, string> m;
map<char, string> first;
map<char, string> follow;

bool isNT(char s) { return ('A'<=s and s<='Z'); }

bool isT(char c) { return !('A'<=c and c<='Z'); }

/* Parse the production rule */
void parse(string s) {

	m[s[0]] = s.substr(s.find("->")+2);
}
/*================================================*/
/* INPUT */
void input() {
	int cnt = 0;
	string s;

	while(getline(cin, s)) {
		Prule.push_back(s);

		if(!cnt) startSymbol = s[0], cnt = 1;
		parse(s);
	}	
}
/*===================================================*/

/* Print the FIRST */
void printFIRST() {
	cout << "FIRST : \n\n";
	map<char, string>::iterator i;
	for(i = first.begin(); i != first.end(); ++i) {
		cout << i->first << " : ";
		string s = i->second;
		cout << "{ ";
		rep(j, 0, s.size()-1) cout << s[j]<<", ";
		cout << s[s.size()-1] <<" }\n\n";
	}
}
/*==================================================*/

/* Print the FOLLOW */
void printFOLLOW() {
	cout << "\nFOLLOW : \n\n";
	map<char, string>::iterator i;
	for(i = follow.begin(); i != follow.end(); ++i) {
		cout << i->first << " : ";
		string s = i->second;
		cout << "{ ";
		rep(j, 0, s.size()-1) cout << s[j]<<", ";
		cout << s[s.size()-1] <<" }\n\n";
	}
}
/*===================================================*/

/*==== Recursively compute the FIRST of every NT ======*/

string findFIRSTrec(char lhs, string rhs, int idx) {

	string ret = "";

	if(idx == rhs.size()) return ret;

	if(rhs[idx] == '0') return ret+="0";

	if(rhs[idx] == '|') idx++;

	if(isT(rhs[idx]))  {
		ret += rhs[idx];
		size_t t = rhs.find("|", idx+1);
		if(t != string::npos) 
			ret += findFIRSTrec(lhs, rhs, t+1);
		
		return ret; 
	}


	if(first.find(rhs[idx]) != first.end()) {
		string f = first[rhs[idx]];
		
		ret += f; 

		if(ret.find("0") != string::npos) {
			ret.erase(ret.find("0"));
			ret += findFIRSTrec(lhs, rhs, idx+1);
		}
	}
	else {

		string str = "";
		str += findFIRSTrec(rhs[idx], m[rhs[idx]], 0);		
		first[rhs[idx]] = str;
		ret += str;
		if(ret.find("0") != string::npos) {
			ret.erase(ret.find("0"));
			ret += findFIRSTrec(lhs, rhs, idx+1);
		}
	}

	return ret;
}

/*======================================================*/

/* Utility function to find FIRST */

void findFIRST() {
	map<char, string>::iterator i;
	for(i = m.begin(); i!=m.end(); ++i) {
		char lhs = i->first;
		if(first.find(lhs) != first.end()) continue;
		string rhs = i->second;
		first[lhs] = findFIRSTrec(lhs, rhs, 0);
	}
}

/*==========================================================*/
#if 0
/* Recursively compute FOLLOW */
string findFOLLOWrec(char lhs, string rhs, int idx) {

	string ret = "";

	if(idx == rhs.size()) return ret += "$";

	if(isT(rhs[idx])) return ret += rhs[idx];

	ret += first[rhs[idx]];

	if(ret.find("0") != string::npos) {
		ret.erase(ret.find("0"));
		ret += findFOLLOWrec(lhs, rhs, idx+1);
	}

	return ret;
}

/*==============================================================*/

/* Utility function to find FOLLOW */

void findFOLLOW() {
	map<char, string>::iterator it, it1;
	for(it = m.begin(); it != m.end(); ++it) {
		char lhs = it->first;
		string ret = "";
		if(lhs == startSymbol) ret += "$";

		for(it1 = m.begin(); it1 != m.end(); ++it1) {
			char l = it1->first;
			string r = it1->second;
			if(r.find(lhs) == string::npos) continue; 

			ret += findFOLLOWrec(l, r, r.find(lhs)+1);
		}

		follow[lhs] = ret;
	}
}
#endif

/*=================================================================*/

int main() {

	input();

	findFIRST();

	printFIRST();
	
	return 0;
}
