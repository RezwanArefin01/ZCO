#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(int argc, char const *argv[]) {
	int n1, n2, n3; cin>>n1>>n2>>n3; 
	int a[n1], b[n2], c[n3]; 
	vector<int> v; map<int,bool> in;
	for(int i=0; i<n1; i++) {
		cin>>a[i]; 
		if(!in.count(a[i])) {
			v.push_back(a[i]);
			in[a[i]] = 1;
		}
	}
	for(int i=0; i<n2; i++) {
		cin>>b[i];
		if(!in.count(b[i])) {
			v.push_back(b[i]);
			in[b[i]] = 1;
		}
	}
	for(int i=0; i<n3; i++) {
		cin>>c[i]; 
		if(!in.count(c[i])) {
			v.push_back(c[i]);
			in[c[i]] = 1;
		}
	}
	sort(v.begin(), v.end());
	map<int,int> com, rev;
	for(int i=0; i<v.size(); i++) 
		com[v[i]] = i, rev[i] = v[i];
	vector<int> vis(51000*3, 0), ans;
	for(int i=0; i<n1; i++) vis[com[a[i]]]++;
	for(int i=0; i<n2; i++) vis[com[b[i]]]++;
	for(int i=0; i<n3; i++) vis[com[c[i]]]++;
	for(int i=0; i<vis.size(); i++) {
		if(vis[i] >= 2) ans.push_back(rev[i]);
	} 
	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); i++) cout<<ans[i]<<endl;
}