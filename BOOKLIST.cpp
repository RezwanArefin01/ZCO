#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6; 
int BIT[maxn];
void update(int x, int val) {
	for(; x <= maxn; x += x & -x) 
		BIT[x] += val;
}
int read(int x){ 
	int sum = 0;
	for(; x > 0; x -= x & -x) 
		sum += BIT[x];
	return sum;
}
int mp[maxn+10], arr[maxn+10];
int main () {
	int m; cin>>m; 
	for(int i=1; i<=m; i++) {
		cin>>arr[i];
		update(i, 1);
		mp[i] = arr[i];
	} 
	int q; cin>>q;
	for(int i=0; i<q; i++) {
		int n; cin>>n;
		int idx = 0, lo = 1, hi = m;
		while(lo <= hi) {
			int mid = lo + hi >> 1;
			if(read(mid) >= n) {
				idx = mid, hi = mid-1;
			} else lo = mid+1;
		} 
		cout<<mp[idx]<<endl;
		update(idx, -1);
	}
}