#include <bits/stdc++.h>
using namespace std;

int main(){
	long int n;
	cin>>n;
	long int arr[n];
	for(long int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long int x = arr[2];
	long int c = 0;
	for(long int i=2;i<n;i++){
		if(arr[i] == x){
			c++;
		}
	}
	if(c > 1){
		if(arr[0] == x){
			c++;
		}
		if(arr[1] == x){
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}