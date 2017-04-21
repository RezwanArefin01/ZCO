#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int par[2222];
int find(int u) {
 	return par[u] == u ? u : par[u] = find(par[u]);
}
void Union(int u, int v){
	par[find(u)] = find(v);
}
bool issame(int u, int v) { return find(u) == find(v);}

typedef pair<int,pair<int, int> > ii;
int main(int argc, char const *argv[]) {
	for(int i=0; i<=2221; i++) 
		par[i] = i;
	int n; scanf("%d", &n);
	int g[n][n]; vector<ii> e;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int x; scanf("%d", &x);
			if(i < j && i != 0) 
				e.push_back(ii(x, pair<int,int>(i,j)));

		}
	} sort(e.begin(), e.end() );
	int k = 0, ans = 0;
	for(int i=0; i<e.size(); i++) {
		ii p = e[i];
		int w = p.first, u = p.second.first, v = p.second.second;
		if(!issame(u, v)) {
			Union(u,v); k++; 
			ans += w;
		} if(k == n-1) break;
	} printf("%d\n", ans);
}
 
