#include <iostream>
#include <vector>
using namespace std;
int f[1000000];

void sort(int s[][],int q){
	int t1,t2,t3;
	for(int i=0;i<q;i++){
		for(int j=0;j<q-i-1;j++){
			if(s[j][0] > s[j+1][0]){
				t1 = s[j][0];t2 = s[j][1];t3 = s[j][2];
				s[j][0] = s[j+1][0];s[j][1] = s[j+1][1];s[j][2] = s[j+1][2];
				s[j+1][0] = t1;s[j+1][0] = t1;s[j+1][0] = t1;
			}
			else if(s[j][0] == s[j+1][0]){
				if(s[j][1] > s[j+1][2]){
					t1 = s[j][0];t2 = s[j][1];t3 = s[j][2];
					s[j][0] = s[j+1][0];s[j][1] = s[j+1][1];s[j][2] = s[j+1][2];
					s[j+1][0] = t1;s[j+1][0] = t1;s[j+1][0] = t1;
				}
			}
		}
	}
}

bool compareInterval(int a[2],int b[2]){
	if(a[0] > b[0]){
		return false;
	}
	else if(a[0] == b[0]){
		if(a[1] == b[1]){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return true;
	}
}

int main() {
	int n,q,s;
	cin>>n;
	s = floor(sqrt(n));
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>q;
	int k[q][3];
	int sk[q][3];
	for(int i=0;i<q;i++){
		cin>>k[i][0]>>k[i][1];
		k[i][2]=sk[i][2] = i;
		sk[i][0] = (int)k[i][0]/s;
		sk[i][1] = k[i][1];
	}
	sort(sk,sk+q,compareInterval);
	int start,end;
	start = end = sk[0][0];
	
	return 0;
}