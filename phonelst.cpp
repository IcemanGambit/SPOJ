#include <bits/stdc++.h>
#include <string>
using namespace std;

int check(vector <string> a, int n){
	int x,y,flag = 0;
	for(int i=0;i<n-1;i++){
		x = a[i].size();y = a[i+1].size();
		if(x==y){
			continue;
		}
		x--;
		while(x>=0){
			if(a[i][x] != a[i+1][x]){
				break;
			}
			x--;
		}
		if(x<0){
			flag =1;
			break;
		}
	}
	return flag;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector <long long int> arr;
		long long int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			arr.push_back(temp);
		}
		sort(arr.begin(),arr.end());
		vector <string> a;
		char tep[11];
		for(int i=0;i<n;i++){
			sprintf(tep,"%lld",arr[i]);
			a.push_back(tep);
		}
		int ans = check(a,n);
		if(ans == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}