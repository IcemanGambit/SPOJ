#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	do{
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		stack <int> s;
		int x = 1;
		for(int i=0;i<n;i++){
			if(arr[i] == x){
				x++;
				continue;
			}
			else{
				if(!s.empty() && s.top() == x){
					x++;
					s.pop();
					i--;
				}
				else{
					s.push(arr[i]);
				}
			}
		}
		while(!s.empty() && x <= n){
			if(s.top() == x){
				x++;
				s.pop();
			}
			else{
				cout<<"no\n";
				break;
			}
		}
		if(s.empty()){
			cout<<"yes\n";
		}
		cin>>n;
	}
	while(n != 0);
	return 0;
}