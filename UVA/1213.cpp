#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> v;
bool prime[1150];
int n,w;
ll dp[200][2300][15];
inline void sieve(){
	memset(prime, true,sizeof prime);
	v.clear();
	prime[1] = false;
	for(int i=2;i<=1120;i++){
		if(prime[i]){
			v.push_back(i);
			for(int j=i*i;j<=1120;j+=i)
				prime[j] = false;
		}
	}
}

inline ll solve(ll current,ll i,ll sum){
	
	if(i==w or current >=v.size() or sum>n) return sum==n? (i==w? 1:0):0;
	if(dp[current][sum][i]!=-1) return dp[current][sum][i];
	
	ll ans = solve(current+1, i+1,sum+v[current]) + 
			 solve(current+1, i, sum);
	return dp[current][sum][i] = ans;
}


main(){
	sieve();
	while(scanf("%d %d",&n,&w)!=EOF and n and w){
			memset(dp,-1,sizeof dp);
			printf("%lld\n",solve(0,0,0));
	}
}
