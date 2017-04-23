#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(int argc, char const *argv[]) {
	int n, l[2] = {0,0}, sa=0, sb=0; cin>>n; 
	for(int i=0; i<n; i++) {
		int a, b; cin>>a>>b;
		sa += a, sb += b;
		l[sa<sb] = max(l[sa<sb], abs(sa-sb));
	} if(l[0] > l[1]) cout<<"1 "<<l[0]<<endl;
	else cout<<"2 "<<l[1]<<endl;
}