#include <bits/stdc++.h>
using namespace std;
int BIT[50000];
int read(int x) {
	int sum = 0;
	for(; x > 0; x -= x&-x)
		sum += BIT[x];
	return sum;
}
void update(int x) {
	for(; x < 50000; x += x & -x) 
		BIT[x]++;
}
int main () {
	int n; cin>>n; 
	int arr[n], a[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i]; 
		a[i] = arr[i];
	}
	sort(a, a+n);
	map<int,int> com; 
	for(int i=1; i<=n; i++) 
		com[a[i-1]] = i;
	for(int i=0; i<n; i++) {
		cout<<i-read(com[arr[i]])+1<<endl;
		update(com[arr[i]]);
	}
}
