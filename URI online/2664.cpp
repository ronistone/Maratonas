#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod = 1000000007;
ll dp[100010][60],n,m,t;

ll solve(int current, int min){
	if(min <= 0) return 1LL;
	if(dp[current][min]!=-1) return dp[current][min];
	
	ll ans = 0LL;
	
	if(current-1 >= n)
		ans += solve(current-1,min-1)%mod;
	if(current+1 <= m)
		ans += solve(current+1,min-1)%mod;

	return dp[current][min] = ans%mod;
}


main(){
	ll ans = 0;
	cin >> t >> n >> m;
	
	memset(dp,-1,sizeof dp);
	for(int i=n;i<=m;i++){
		ans += solve(i,t)%mod;
	}
	cout << ans%mod << endl;
}
