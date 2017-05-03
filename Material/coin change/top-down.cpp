#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-2

typedef long long int ll;
int M[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};

ll dp[11][40100];
ll n;

ll solve(ll current, ll sum){
	
	if(sum==0) return dp[current][sum] = 1LL;
	if(current < 0 or sum < 0) return 0LL;
	
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ll ans = solve(current,sum-M[current]) + solve(current-1,sum);
	
	return dp[current][sum] = ans;
	
}

main(){
	float aux;
	memset(dp,-1,sizeof dp);
	while(cin >> aux and aux!= 0.00){
		n = (ll)(aux*100);
		if(fabs(aux*100 - n) > EPS)
			n++;
		printf("%6.2f %16lld\n", aux, solve(10,n));
	}

}
