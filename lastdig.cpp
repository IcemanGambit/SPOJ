#include <bits/stdc++.h>
using namespace std;

int func(int a, string b){
	if(a == 0 && b.size()==1 && b[0] == '0'){
		return 1;
	}
		if(a == 0 && b.size()==1 && b[0] != '0'){
		return 0;
	}
	if(b.size()==1 && b[0] == '0'){
		return 1;
	}
	int mod = 0;
	for(int i=0;i<b.size();i++){
		mod = ((mod*10) + b[i]-'0')%4;
	}
	if(mod == 0){
		mod = 4;
	}
	int ans = pow(a%10,mod);
	return (ans%10);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,ans;
		string b;
		cin>>a>>b;
		ans = func(a,b);
		cout<<ans<<endl;
	}
	return 0;
}