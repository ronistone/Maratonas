#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[30][100];
ll D[30];
ll n,m;

ll solve(ll current,ll sum){
	if(sum==m) return 0LL;
	if(current==n){
		return 1000000LL;
	}
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ll ans = min(min(solve(current+1,sum),solve(current+1,sum+D[current])+1LL),solve(current,sum+D[current])+1LL);
	
	return dp[current][sum] = ans;
}

main(){
	int z;
	cin >> z;
	
	for(int k=0;k<z;k++){
		cin >> n >> m;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			cin >> D[i];
		}
		cout << solve(0,0) << endl;
	}
}
