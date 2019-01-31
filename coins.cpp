#include <bits/stdc++.h>
using namespace std;
long long int dp[100000000];

long long int max(long long int a, long long int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

long long int dprec(long long int n){
	long long int x;
	if(dp[n] == -1){
		x = dprec(n/2) + dprec(n/3) + dprec(n/4);
		dp[n] = max(x,n);
	}
	return dp[n];
}

int main(){
	long long int n;
	while(cin>>n){
		cin.clear();
		dp[0]=0;dp[1]=1;
		for(long long int i=2;i<=n+1;i++){
			dp[n] = -1;
		}
		long long int ans = dprec(n);
		cout<<ans<<endl;
	}
	return 0;
}