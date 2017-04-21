#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1000010], g[1000010];
int main () {
	f[0] = f[1] = 1;
	f[2] = 2;
	g[0] = 0, g[1] = 1;
	int n; cin>>n;
	for(int i=2; i<=n; i++) {
		f[i] = f[i-1] + f[i-2] + 2*g[i-2];
		g[i] = f[i-1] + g[i-1];
		f[i] %= 10000;
		g[i] %= 10000;
	} cout<<f[n]<<endl;
}
