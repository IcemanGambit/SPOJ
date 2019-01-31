#include <bits/stdc++.h>
using namespace std;

string reverse(string str){
	string rev;
	for(int i=1;i<=str.length();i++){
		rev.push_back(str[str.length()-i]);
	}
	return rev;
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int LCS(string str, string rev){
	int m,n;
	m = str.length();
	n = rev.length();
	int l[m+1][n+1];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0){
				l[i][j] = 0;
			}
			else if(str[i-1] == rev[j-1]){
				l[i][j] = l[i-1][j-1] +1;
			}
			else{
				l[i][j] = max(l[i-1][j],l[i][j-1]);
			}
		}
	}
	return l[m][n];
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		string str,rev;
		cin>>str;
		n = str.size();
		rev = reverse(str);
		int ans = n-LCS(str,rev);
		cout<<ans<<endl;
	}
	return 0;
}