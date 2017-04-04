#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
map<ll,ll> A;
ll num[30];
ll dp[30][300];
ll solve(ll x,ll at){
	if(x >= n) return 1;
	if(dp[x][at]!=-1) return dp[x][at];
	
	ll ans;
	if(num[x+1] > num[at])
		ans = max(solve(x+1,x)+1,solve(x+1,at));
	else
		ans = solve(x+1,at);
		
	return dp[x][at] = ans;

}


main(){
	ll aux;
	while(cin >> n){
		for(int j=0;j<n;j++){
			cin >> aux;
			A[aux] = j;
		}
		//ll ans = -10e17;
		for(int j=0;j<n-1;j++){
			for(int k=0;k<n;k++){
				cin >> aux;
				num[k] = A[aux];
			}
			memset(dp,-1,sizeof dp);
			cout << "J:" << j << "  ---> " << solve(0,0) << endl;
		}
	}

}
