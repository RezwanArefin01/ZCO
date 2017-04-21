#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5; 
int BIT[maxn+100], n, I[maxn+10], arr[maxn+10];
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
int f(int k) {
	int lo = 1, hi = n, ret = 0;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(read(mid) >= k) {
			hi = mid-1, 
			ret = mid; 
		}
		else lo = mid+1;
	} 
	return ret;
}
int main () {
	scanf("%d", &n);
	for(int i=1;i <=n; i++) {
		scanf("%d", &I[i]);
		update(i, 1);
	} 
	for(int i=n; i>=1; i--) {
		int k = f(I[i] + 1);
		arr[n-k+1] = i;
		update(k, -1);
	}
	for(int i=1; i<=n; i++) 
		printf("%d ", arr[i]);
}