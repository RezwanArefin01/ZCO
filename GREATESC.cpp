//declare all variable in global.. or you'll
//get Segmentation Falut!! Bug in Judge! till now!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3500;
vector<int> adj[maxn]; 
int dist[maxn], vis[maxn], s, d, n, m, u, v; 
int main(int argc, char const *argv[]) {
	cin>>n>>m; 
	while(m--) {
		cin>>u>>v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} cin>>s>>d; 
	s--, d--;
	queue<int> Q; 
	Q.push(s);
	vis[s] = 1;
	dist[0] = 0;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		for(int i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if(!vis[v]) {
				vis[v] = 1;
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	} 
	cout<<dist[d]<<endl;
}