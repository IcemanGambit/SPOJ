#include <bits/stdc++.h>
using namespace std;

int main(){
	long int x1,x2,y1,y2,x,y;
	cin>>x1>>y1>>x2>>y2;
	cin>>x>>y;
	long int p,q;
	p = (x2-x1)/x;
	q = (y2-y1)/y;
	if((p%2==0 && q%2==0) || (p%2==1 && q%2==1)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}