#include <bits/stdc++.h>
using namespace std;

pair <int,int> max(pair <int,int> a,pair <int,int> b){
	if(a.second>b.second){
		return a;
	}
	if(a.second == b.second){
		if(a.first < b.first){
			return a;
		}
		else{
			return b;
		}
	}
	return b;
}

pair <int,int> knapsack(int arr[][2],int w,int n){
	pair <int,int> k[n+1][w+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(i==0 || j==0){
				k[i][j] = make_pair(0,0);
			}
			else if(arr[i-1][0] <= j){
				pair <int,int> a = k[i-1][j-arr[i-1][0]];
				k[i][j] = max(make_pair(arr[i-1][0]+a.first,arr[i-1][1]+a.second),k[i-1][j]);
			}
			else{
				k[i][j] = k[i-1][j];
			}
		}
	}
	return k[n][w];
}

int main(){
	int w,n;
	cin>>w>>n;
	while(w!=0 && n!=0){
		int arr[n][2];
		for(int i=0;i<n;i++){
			cin>>arr[i][0]>>arr[i][1];
		}
		pair <int,int> a=knapsack(arr,w,n);
		cout<<a.first<<" "<<a.second<<endl;
		cin>>w>>n;
	}
	return 0;
}