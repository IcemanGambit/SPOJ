#include <bits/stdc++.h>
using namespace std;

long long int max(long long int dp[],long long int n){
	long long int max =-1;
	for(long long int i=0;i<n;i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}
	return max;
}

int main(){
	int t,k=0;
	cin>>t;
	while(t--){
		k++;
		long long int n;
		cin>>n;
		if(n==0){
			cout<<"Case "<<k<<": 0"<<endl;
			continue;
		}
		long long int arr[n],dp[n];
		for(long long int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(long long int i=0;i<n;i++){
			if(i==0 || i==1){
				dp[i] = arr[i];
			}
			else{
				dp[i] = max(dp,i-1)+arr[i];
			}
		}
		long long int ans = max(dp,n);
		cout<<"Case "<<k<<": "<<ans<<endl;
	}
	return 0;
}