#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,arr[5000];
	char s[5000];
	while(1){
		cin>>s;
		int x = s[0]-'0';
		if(x == 0){
			break;
		}
		else{
			int n = strlen(s);
			int a,b,num,dp[n];
			dp[0] = 1;
			for(int i=1;i<n;i++){
				a = s[i-1]-'0';
				b = s[i]-'0';
				int num = a*10 + b;
				if(num < 27){
					dp[i] = dp[i-1]+1;
				}
				else{
					dp[i] = dp[i-1];
				}
			}
			cout<<dp[n-1];
		}
	}
	return 0;
}