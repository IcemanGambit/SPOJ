#include <bits/stdc++.h>
using namespace std;
int n;
int arr[21][21];
long long int allmask;
long long int dp[1 << 20];

long long int countways(long long int mask){
	if(mask == allmask){
		return 1;
	}
	int i = __builtin_popcount(mask);
	if(dp[mask] != -1){
		return dp[mask];
	}
	long long int ways = 0;
	for(int j=0;j<n;j++){
		if(arr[i][j] == 0 || mask & (1 << j)){
			continue;
		}
		else{
			ways += countways(mask|(1 << j));
		}
	}
	return dp[mask] = ways;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		allmask = (1 << n) -1;
		memset(dp,-1,sizeof dp);
		long long int ans = countways(0);
		printf("%lld\n",ans);
	}
	return 0;
}