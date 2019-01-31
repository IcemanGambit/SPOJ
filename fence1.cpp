#include <bits/stdc++.h>
using namespace std;
float pi= 3.14159;
int main(){
	int l;
	cin>>l;
	while(l!=0){
		float f = (pi*(l/pi)*(l/pi))/2;
		printf("%.2f\n",f);
		cin>>l;
	}
	return 0;
}