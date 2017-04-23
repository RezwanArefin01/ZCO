#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 1e5+10; 
ll dp[maxn][2], n, w[maxn];
vector<int> adj[maxn];
void dfs(int u, int par) {
	dp[u][0] = 0;
	dp[u][1] = w[u];
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if(v == par) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][1], dp[v][0]);
		dp[u][1] += dp[v][0];
	} 
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
	} dfs(0,-1);
	cout<<max(dp[0][1], dp[0][0])<<endl;
} 
