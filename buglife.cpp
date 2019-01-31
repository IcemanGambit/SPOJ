#include <bits/stdc++.h>
using namespace std;
int g[2000][2000];

bool util(int src,int n,int c[]){
	c[src] = 1;
	queue <int> q;
	q.push(src);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(g[x][i] && c[i] == -1){
				c[i] = 1-c[x];
				q.push(i);
			}
			else if(g[x][i] && c[x] == c[i]){
				return false;
			}
		}
	}
	return true;
}

int isbipartite(int n){
	int c[n];
	for(int i=0;i<n;i++){
		c[i] = -1;
	}
	for(int i=0;i<n;i++){
		if(c[i] == -1){
			if(util(i,n,c) == false){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int t,m,n,p,q,k=1,ans;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				g[i][j] = 0;
			}
		}
		for(int i=0;i<m;i++){
			cin>>p>>q;
			g[p-1][q-1] = 1;
			g[q-1][p-1] = 1;
		}
		ans = isbipartite(n);
		cout<<"Scenario #"<<k<<":\n";
		if(ans == 0){
			cout<<"Suspicious bugs found!"<<endl;
		}
		else{
			cout<<"No suspicious bugs found!"<<endl;
		}
		k++;
	}
	return 0;
}
