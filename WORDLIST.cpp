#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(int argc, char const *argv[]) {
	int t; cin>>t; string str;
	getline(cin, str);
	set<string> st;
	while(t--) {
		getline(cin, str); 
		for(int i=0; i<str.size(); i++) {
			char &c = str[i];
			if(c == '\'' || c == '.' || c == ',' || 
				c == ';' || c == ':' ) c = ' ';
		} string tmp;
		istringstream ss(str);
		while(ss>>tmp) {
			for(int i=0; i<tmp.size(); i++) 
				tmp[i] = tolower(tmp[i]);
			st.insert(tmp);
		}
	} cout<<st.size()<<endl;
	for(set<string>::iterator it = st.begin(); it != st.end(); ++it) 
		cout<<*it<<endl;
}