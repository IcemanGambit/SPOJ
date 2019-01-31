#include <bits/stdc++.h>
using namespace std;
unsigned long int arr[1000][1000];
unsigned long int maximum = 999999999;

int minkey(unsigned long int key[],bool mstset[],int n){
	int index,min = maximum;
	for(int i=0;i<n;i++){
		if(mstset[i] == false && key[i]<min){
			min = key[i];
			index = i;
		}
	}
	return index;
}

unsigned long int mst(int n){
	int parent[n];
	unsigned long int key[n];
	bool mstset[n];
	for(int i=0;i<n;i++){
		key[i] = maximum;
		mstset[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	unsigned long int val=0;
	for(int i=0;i<n-1;i++){
		int u = minkey(key,mstset,n);
		mstset[u] = true;
		for(int j=0;j<n;j++){
			if(arr[u][j] && mstset[j]==false && arr[u][j]<key[j]){
				parent[j] = u;
				key[j] = arr[u][j];
			}
		}
	}
	for(int i=1;i<n;i++){
		val += arr[i][parent[i]];
	}
	return val;
}

int main(){
	int t,p,n,a,b;
	unsigned long int c,m;
	cin>>t;
	while(t--){
		cin>>p>>n>>m;
		memset(arr,0,sizeof arr);
		for(unsigned long int i=0;i<m;i++){
			cin>>a>>b>>c;
			arr[a-1][b-1] = arr[b-1][a-1] = c;
		}
		unsigned long int ans = mst(n);
		ans = p*ans;
		cout<<ans<<endl;
	}
	return 0;
}