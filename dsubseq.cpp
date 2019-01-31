#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		int n= a.size();
		int dp[n],last[n];
		long long sum[n];
		dp[0] = 1;
		sum[0] = 1;
		for(int i=0;i<n;i++){
			last[a[i]-'0'] = i;
		}
		for(int i=1;i<n;i++){
			dp[i] = sum[i-1] - sum[last[a[i-1]-'0']-1];
			sum[i] = sum[i-1] + dp[i];
			last[a[i-1]-'0'] = i;
		}
		sum[n] = (sum[n]%1000000007+1000000007)%1000000007;
		cout<<sum[n]<<endl;
	}
	return 0;
}