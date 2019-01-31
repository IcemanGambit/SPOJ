#include <bits/stdc++.h>
using namespace std;

string tostring(int n){
	stringstream ss;
	ss<<n;
	return ss.str();
}

bool check(int n){
	if(n==0)
		return false;
	else{
		while(n!=0){
			if(n%10>1){
				return false;
			}
			n = n/10;
		}
	}
	return true;
}

int divide(string str,int n){
	int l = str.length();
	int t = str[0]-'0';
	for(int i=1;i<l;i++){
		t = t%n;
		t = t*10+(str[i]-'0');
	}
	return t%n;
}

string solve(int n,pair <int,string> x){
	queue <pair <int,string> > q;
	q.push(x);
	int mod;
	while(!q.empty()){
		pair <int,string> tmp = q.front();
		q.pop();
		mod = divide(tostring(tmp.first)+tmp.second[tmp.second.size()-1],n);
		if(mod == 0){
			return tmp.second;
		}
		q.push(make_pair(mod,tmp.second+"0"));
		q.push(make_pair(mod,tmp.second+"1"));
	}
}

int main(){
	int k;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		string s,str;
		str = n;
		if(check(n))
			cout<<n<<endl;
		else{
			for(int i=0;i<=str.length();i++)
				s = s+"1";
			string ans = solve(n,make_pair(1,s));
			cout<<ans<<endl;
		}
	}
	return 0;
}