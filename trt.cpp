#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];

int solve(int v[],int l,int r,int age){
	if(l == r){
		return dp[l][r] = v[l]*age;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	dp[l][r] = max(solve(v,l+1,r,age+1) + v[l]*age, solve(v,l,r-1,age+1) + v[r]*age);
	return dp[l][r];
}

int main(){
	int n;
	cin>>n;
	int v[n];
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	memset(dp,-1,sizeof dp);
	int ans = solve(v,0,n-1,1);
	cout<<ans;
	return 0;
}