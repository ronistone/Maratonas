#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;

ll n,M[30];
ll dp[30][20000];

ll solve(ll current, ll sum){
	
	if(sum==0) return 1LL;
	if(current < 1 or sum < 0) return 0LL;
	
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ll ans = solve(current,sum-M[current]) + solve(current-1,sum);
	
	return dp[current][sum] = ans;
}



main(){
	for(int i=1;i<22;i++) M[i] = i*i*i;
	memset(dp,-1,sizeof dp);
	while(cin >> n){
		cout << solve(21,n) << endl;
	}

}
