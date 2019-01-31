#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int p1=0,p2=0;

int dynamic(int arr,int l,int r){
	if(l<r){
		return 0;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	return dp[l][r] = max(dynamic(arr,l+1,r)+arr[l],dynamic(arr,l,r-1)+arr[r]);
}

int solve(int arr[],int l,int r,int c){
	if(c==0){
		memset(dp,-1,sizeof dp);
		int a = dynamic(arr,l,r);
		a = dp[1][1];
		p1 += a;
		if(a == arr[l]){
			solve
		}
	}
}

int main(){
	int n,x=1;
	cin>>n;
	while(n!=0){
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		memset(dp,-1,sizeof dp);
		int ans = solve(arr,0,n-1,0);
		printf("In game %d, the greedy strategy might lose by as many as %d points.",++x,ans);
		cin>>n;
	}
	return 0;
}