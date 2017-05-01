#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
	int m; scanf("%d", &m);
	int arr[m];
	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = min(a,b);
	} sort(arr, arr+m);
	int prev = 0, ans = 0;
	for(int i=0; i<m; i++) 
		if(arr[i] > prev) prev++, ans++;
	printf("%d\n", ans);
}