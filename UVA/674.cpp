#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-3
#define endl '\n'

typedef long long int ll;

int M[] = {50,25,10,5,1};
ll dp[5][10000],n;

ll solve(ll current,ll sum){

	if(sum == 0) return 1LL;
	if(current<0 or sum<0) return 0LL;
	
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ll ans = solve(current,sum-M[current]) + solve(current-1,sum);
	
	return dp[current][sum] = ans;
}

main(){
	
	memset(dp,-1,sizeof dp);
	while(cin >> n){
		cout << solve(4,n) << endl;
	}

}
