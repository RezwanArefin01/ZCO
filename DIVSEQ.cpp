#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[10010], arr[10010];
int main () {
	int n; cin>>n; 
	for(int i=0; i<n; i++) 
		cin>>arr[i];
	dp[0] = 1;
	for(int i=1; i<n; i++) {
		dp[i] = 1;
		for(int j=0; j<i; j++) 
			if(arr[i] % arr[j] == 0) 
				dp[i] = max(dp[i], dp[j]+1);
	} int Max = 1;
	for(int i=0; i<n; i++)
		Max = max(Max, dp[i]);
	cout<<Max<<endl;
}
