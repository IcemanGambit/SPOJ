#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c){
	if(a<=b && a<=c){
		return a;
	}
	if(b<=a && b<=c){
		return b;
	}
	if(c<=a && c<=a){
		return c;
	}
}

int LCS(char a[],char b[],int n,int m){
	int l[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0){
				l[i][j] = j;
				continue;
			}
			if(j==0){
				l[i][j] = i;
				continue;
			}
			if(a[i-1] == b[j-1]){
				l[i][j] = l[i-1][j-1];
			}
			else{
				l[i][j] = min(l[i-1][j],l[i][j-1],l[i-1][j-1]) + 1;
			}
		}
	}
	return l[n][m];
}

int main(){
 	int t;
 	cin>>t;
 	while(t--){
 		char a[2001],b[2001];
 		cin>>a>>b;
 		int n,m,ans;
 		n = strlen(a);
 		m = strlen(b);
 		ans = LCS(a,b,n,m);
 		cout<<ans<<endl;
 	}
 	return 0;
 }