#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> ii;

int main(int argc, char const *argv[]) {
	int n, num; cin>>n; 
	vector<int> d;
	for(int i=0; i<n; i++){
		cin>>num;
		vector<int>::iterator it = upper_bound(d.begin(), d.end(), num);
		if(it == d.end()) d.push_back(num);
		else *it = num;
	} cout<<n - d.size()<<endl;
}