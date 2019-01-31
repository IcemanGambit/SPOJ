#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int dp[100][100];
int n,m;

int max(int a,int b,int c){
	if(a>=b && a>=c){
		return a;
	}
	if(b>=c && b>=c){
		return b;
	}
	if(c>=a && c>=b){
		return c;
	}
}

int pathcost(int i,int j){
	if(j<0 || j>m-1){
		return 0;
	}
	if(i==0){
		return arr[i][j];
	}
	if(dp[i][j] == -1){
		dp[i][j] = max(pathcost(i-1,j-1),pathcost(i-1,j),pathcost(i-1,j+1)) + arr[i][j];
	}
	return dp[i][j];
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int temp;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&temp);
				arr[i][j] = temp;
				dp[i][j] = -1;
			}
		}
		int max = -1,x;
		for(int i=0;i<m;i++){
			x = pathcost(n-1,i);
			if(x > max){
				max = x;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}