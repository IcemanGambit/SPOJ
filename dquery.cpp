#include <bits/stdc++.h>
using namespace std;
int block;
int hash[1000000];

bool compfunc(pair <int,pair <int,int> > a,pair <int,pair <int,int> > b){
	if(a.second.first/block < b.second.first/block){
		return true;
	}
	else if(a.second.first/block == b.second.first/block){
		if(a.second.second < b.second.second){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

int main(){
	int n,a,b;
	scanf("%d",&n);
	block = sqrt(n);
	long long int q,temp;
	vector <long long int> arr;
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		arr.push_back(temp);
	}
	scanf("%lld",&q);
	vector <pair <int,pair <int,int> > > lrr;
	for(long long int i=0;i<q;i++){
		scanf("%d %d",&a,&b);
		lrr.push_back(make_pair(i,make_pair(a,b)));
	}
	sort(lrr.begin(),lrr.end(),compfunc);
	memset(hash,0,sizeof hash);
	int l,r,ml,mr,ans[q];
	l =0;r =-1;
	int count =0;
	for(long long int i=0;i<q;i++){
		ml = lrr[i].second.first-1;
		mr = lrr[i].second.second-1;
		while(r < mr){
			r++;
			hash[arr[r]]++;
			if(hash[arr[r]] == 1){
				count++;
			}
		}
		while(l < ml){
			hash[arr[l]]--;
			if(hash[arr[l]] == 0){
				count--;
			}
			l++;
		}
		while(r > mr){
			hash[arr[r]]--;
			if(hash[arr[r]] == 0){
				count--;
			}
			r--;
		}
		while(l > ml){
			l--;
			hash[arr[l]]++;
			if(hash[arr[l]] == 1){
				count++;
			}
		}
		ans[lrr[i].first] = count;
	}
	for(long long int i=0;i<q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}