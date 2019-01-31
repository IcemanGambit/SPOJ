#include <iostream>
#include <vector>
using namespace std;
vector <int> sieve (1000000,1);
void prime(){
	for(int i=2;i<1000000;i++){
		for(int j=2;i*j<1000000;j++){
			if(sieve[i*j] == 1){
				sieve[i*j] = 0;
			}
		}
	}
	sieve[0] = 0;
	sieve[1] = 0;
}

int main() {
	int t,n,m;
	prime();
	cin>>t;
	while(t){
		cin>>n>>m;
		for(int i=n;i<=m;i++){
			if(sieve[i] == 1){
				cout<<i<<"\n";
			}
		}
		t--;
	}
	return 0;
}