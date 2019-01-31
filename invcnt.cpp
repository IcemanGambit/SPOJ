#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long temp[],long long l, long long mid, long long r){
	long long inv=0;
	long long i,j,k;
	i = l;j = mid;k =l;
	while(i<=mid-1 && j<=r){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			inv = inv+(mid-i);
		}
	}
	while(i<=mid-1)
		temp[k++]=arr[i++];
	while(j<=r)
		temp[k++]=arr[j++];
	for(i=l;i<=r;i++){
		arr[i] = temp[i];
	}
	return inv;
}

long long sort(long long arr[],long long temp[],long long l, long long r){
	long long mid, inv=0;
	if(r > l){
		mid = (r+l)/2;
		inv = sort(arr,temp,l,mid);
		inv = inv+sort(arr,temp,mid+1,r);
		inv = inv+merge(arr,temp,l,mid+1,r);
	}
	return inv;
}

long long mergesort(long long arr[], long long n){
	long long temp[n];
	return sort(arr,temp,0,n-1);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long arr[n];
		for(long long i=0;i<n;i++){
			cin>>arr[i];
		}
		long inv =0;
		inv = mergesort(arr,n);
		cout<<inv<<endl;
	}
	return 0;
}