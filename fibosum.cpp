#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

void multiply(long long int F[2][2],long long int M[2][2]);
void power(long long int F[2][2], int n);

int fib(int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
 
void power(long long int F[2][2], int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
void multiply(long long int F[2][2],long long int M[2][2])
{
  long long int x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0]%mod)%mod;
  long long int y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1]%mod)%mod;
  long long int z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0]%mod)%mod;
  long long int w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1]%mod)%mod;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
  	
int Sum(int n){
    return fib(n+2) - 1;
}

int main(){
	int t,n,m;
	long long int a;
	cin>>t;
	while(t--){
		cin>>n>>m;
		a = (Sum(m) - Sum(n-1))%mod;
		if(a < 0){
			a = a + mod;
		}
		a = a%mod;
		cout<<a<<endl;
	}
}