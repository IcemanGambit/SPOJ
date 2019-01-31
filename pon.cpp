#include <bits/stdc++.h>
using namespace std;

unsigned long long int pow(unsigned long long int a, unsigned long long int d){
	unsigned long long int temp;
	if(d==0)
		return 1;
	temp = pow(a,d/2);
	if(d%2==0){
		return temp*temp;
	}
	else{
		return a*temp*temp;
	}
}

bool miller(unsigned long long int n, unsigned long long int d){
	unsigned long long int a = 2+ rand()%(n-4);
	unsigned long long int x = pow(a,d)%n;
	if(x==1 || x==n-1){
		return true;
	}
	while(d!=n-1){
		x = (x*x)%n;
		if(x==1)
			return false;
		if(x==n-1)
			return true;
	}
}

bool isprime(unsigned long long int n,int k){
	if(n==1 || n==4){
		return false;
	}
	if(n<=3){
		return true;
	}
	unsigned long long int d= n-1;
	while(d%2 == 0){
		d = d/2;
	}
	for(int i=0;i<k;i++){
		if(miller(n,d) == false){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		unsigned long long int n;
		cin>>n;
		if(isprime(n,5) == true){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}