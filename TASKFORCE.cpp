#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3500;
int n, m, k, hate[maxn], g[maxn][maxn];
int main(int argc, char const *argv[]) {
	scanf("%d %d %d", &n, &m, &k);
	while(m--) {
		int u, v; 
		scanf("%d %d", &u, &v);
		hate[u]++, hate[v]++;
		g[u][v] = g[v][u] = 1;
	}
	while(true) {
		int u = -1;
		for(int i=1; i<=n; i++) 
			if(hate[i] > 0 && hate[i] < k) 
				u = i; 

		if(u == -1) break;
		for(int v=1; v<=n; v++) if(g[u][v]){
			g[u][v] = g[v][u] = 0;
			hate[v]--;
			hate[u]--; 
		}
	} int cnt = 0;
	for(int i=1; i<=n; i++) 
		cnt += (hate[i] >= k);
	if(cnt) printf("YES\n%d",cnt);
	else printf("NO\n");
}