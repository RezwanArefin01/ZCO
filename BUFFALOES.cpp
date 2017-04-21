#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 410;
int dp[maxn][maxn];
int main(int argc, char const *argv[]) {
    int n, K; cin>>n>>K;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    K -= K&1;
    int Max = 0;
    for(int k=1; k<=K; k++) {
        for(int i=k; i<=n; i++) {
            dp[k][i] = *max_element(dp[k-1]+k-1, dp[k-1]+i) + 
                       (k&1? -1:1) * arr[i-1];
            Max = max(Max, dp[k][i]);
        }
    } cout<<Max<<endl;
}
