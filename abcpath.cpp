#include <bits/stdc++.h>
using namespace std;
char arr[51][51];
int h,w;
int dp[51][51];
int x[8] = {-1,0,1,1,1,0,-1,-1};
int y[8] = {-1,-1,-1,0,1,1,1,0};

void solve(int a,int b,int s){
	for(int i=0;i<8;i++){
		int p = a+x[i];
		int q = b+y[i];
		if(p>=0 && p<h && q>=0 && q<w){
			if(arr[p][q] == arr[a][b]+1){
				if(dp[p][q] < s+1){
					dp[p][q] = s+1;
					solve(p,q,s+1);
				}
			}
		}
	}
	return;
}

int main(){
	int c=0;
	cin>>h>>w;
	while(h!=0 && w!= 0){
		char t;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>t;
				arr[i][j] = t;
			}
		}
		int max =0;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(arr[i][j] == 'A'){
					dp[i][j] = 1;
					solve(i,j,1);
				}
			}
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(dp[i][j] > max)
					max = dp[i][j];
			}
		}
		printf("Case %d: %d\n",++c,max);
		cin>>h>>w;
	}
	return 0;
}