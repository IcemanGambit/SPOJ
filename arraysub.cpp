#include <bits/stdc++.h>
using namespace std;

long long int findmax(long long int arr[], int n, int m){
	long long int max = -1;
	for(int i=n;i<=m;i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

int main(){
	int n,n2,k,t,l,r;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	n2 = n-k+1;
	long long int ans[n2];
	l = 0;r = k-1;
	long long int max = findmax(arr,l,r);
	ans[l] = max;
	while(r < n){
		r++;
		if(arr[l] == max){
			l++;
			max = findmax(arr,l,r);
		}
		else{
			if(arr[r] >= max){
				max = arr[r];
				l++;
			}
		}
		if(r-l == k){
			l++;
		}
		ans[l] = max;
	}
	for(int i=0;i<n2;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}