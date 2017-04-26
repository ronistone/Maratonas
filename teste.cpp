#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


ll dp[100010];

ll solve(ll at){
	if(at==1) return 1LL;
	if(at==2) return 2LL;
	
	if(dp[at]!=-1) return dp[at];
	
	ll ans = solve(at-1) + solve(at-2);
	
	return dp[at] = ans;
} 


main(){

	int t,n;
	cin >> t;
	
	for(int i=0;i<t;i++){
		
		cin >> n;
		memset(dp,-1,sizeof dp);
		cout << solve(n) << endl;
		
	}
	
}
