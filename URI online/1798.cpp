#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long int ll;
typedef pair<int,int> ii;
int w,n,a,b,i;
ii A[1005];
ll dp[1005][15000];

ll solve(ll current,ll sum){
	
	if(sum == w) return 0LL;
	if(current >= n) return LLONG_MIN;
	
	if(dp[current][sum] != -1) return dp[current][sum];
	
	ll ans = solve(current+1,sum);
	
	if(sum+A[current].F <= w)
		ans = max(solve(current,sum+A[current].F)+A[current].S,ans);
		
	return dp[current][sum] = ans;
}
main(){
	while(cin >> n >> w){
		memset(dp,-1,sizeof dp);
		for(i=0;i<n;i++)
			cin >> A[i].F >> A[i].S;
		cout << solve(0,0) << endl;
	}
}
