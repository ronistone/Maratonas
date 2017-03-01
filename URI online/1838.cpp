#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long int ll;
typedef pair<ll,ll> ii;

ll dp[3700][1100];
vector<ii> D;
ll n;

ll solve(ll current,ll X){
	if(current >=3600 or X>=n) return 0;
	
	if(dp[current][X]!=-1) return dp[current][X];
	
	ll ans = D[X].S-D[X].F;
	
	if(D[X].F >=current)
		ans = max(solve(D[X].S,X+1)+ans,solve(current,X+1));
	else
		ans = solve(current,X+1);
	
	return dp[current][X] = ans;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll X,Y;
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> X >> Y;
		D.pb(mp(X,Y));
	}
	sort(D.begin(),D.end());
	memset(dp,-1,sizeof dp);
	cout << solve(1,0) << endl;
}
