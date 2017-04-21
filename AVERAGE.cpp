#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int arr[maxn];
int main(int argc, char const *argv[]) {
	int n; cin>>n; 
	for(int i=0; i<n; i++) 
		cin>>arr[i];
	sort(arr, arr+n);
	int ans = 0;
	for(int i=0; i<n; i++) {
		if(arr[i] == arr[i+1] || i && arr[i] == arr[i-1]) 
			{ans ++; continue; }
		int l = i-1, r = i+1; 
		while(l >= 0 && r < n) {
			int avg = arr[l] + arr[r];
			if(avg == 2*arr[i]) {ans++; break;}
			if(avg > 2*arr[i]) l--; 
			else r++;
		}
	} cout<<ans<<endl;
}