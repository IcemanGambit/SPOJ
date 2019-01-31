#include <bits/stdc++.h>
using namespace std;
int MAX = 99999999;

int dynamic(int wt,int n,int p[],int w[]){
	int dp[wt+1];
	dp[0] = 0;
	for(int i=1;i<=wt;i++){
		dp[i] = MAX;
	}
	for(int i=0;i<=wt;i++){
		for(int j=0;j<n;j++){
			if(w[j] <= i){
				dp[i] = min(dp[i],dp[i-w[j]]+p[j]);
			}
		}
	}
	return dp[wt];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int e,f,n;
		cin>>e>>f;
		cin>>n;
		int p[n],w[n];
		for(int i=0;i<n;i++){
			cin>>p[i]>>w[i];
		}
		int wt = f-e;
		int ans = dynamic(wt,n,p,w);
		if(ans != MAX){
			cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
		}
		else{
			cout<<"This is impossible.\n";
		}
	}
	return 0;
}