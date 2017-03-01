#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n,m;
ll dp[200001][2];
ll D[200001];

inline ll solve(ll current,bool buy){
		
	if(current==n) return 0;
	
	if(dp[current][buy]!=-1) return dp[current][buy];
	
	ll ans = 0;
	if(buy)
		ans = max(solve(current+1,false)+D[current],solve(current+1,true));
	else
		ans = max(solve(current+1,true)-D[current]-m,solve(current+1,false));
	
	return dp[current][buy] = ans;
	
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n){
		cin >> m;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			cin >> D[i];
		}
		cout << solve(0,false) << endl;
	}
}
