#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[1010][10000];

ll n,v;

ll solve(int current,int sum){
	
	if(current > n) return 0LL;
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ll ans = 0LL;
	for(int i=1;i<=6;i++){
		ans += solve(current+1,sum+i) + (sum+i>=v?1LL:0LL);
	}
	return dp[current][sum] = ans;	
}


main(){
	memset(dp,-1,sizeof dp);
	while(cin >> n >> v){
		memset(dp,-1,sizeof dp);
		
		cout << fixed << setprecision(4) << (solve(0,0)/(6.0*n)) << endl;
		cout << solve(0,0) << endl;
	}
}
