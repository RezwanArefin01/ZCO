#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3010;
ll n, w[maxn], timer = 0, in[maxn], out[maxn],f[maxn];
vector<int> adj[maxn];
void dfs(int u, int par) {
	in[u] = ++timer; 
	f[u] = w[u];
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(v == par) continue;
		dfs(v, u); 
		f[u] += f[v];
	} out[u] = ++timer;
} 
bool ispar(int u, int v) {
	return (in[u] < in[v] && out[u] > out[v]);
}
int main(int argc, char const *argv[]) {
	cin>>n;
	for(int i=0; i<n; i++) 
		cin>>w[i];
	for(int i=0; i<n-1; i++) {
		int u, v; cin>>u>>v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} dfs(0, -1);
	ll Min = 1e18;
	for(int u=0; u<n; u++) for(int v=u+1; v<n; v++) {
		ll sz = 0;
		if(ispar(u,v)) {
			sz = max(f[v], f[u] - f[v]);
			sz = max(sz, f[0] - f[u]);
		} else if(ispar(v,u)) {
			sz = max(f[u], f[v] - f[u]);
			sz = max(sz, f[0] - f[v]);
		} else {
			sz = max(f[u], f[v]);
			sz = max(sz, f[0] - f[u] - f[v]);
		} Min = min(Min ,sz);
	} cout<<Min<<endl;
}