#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[200][3];
ll D[200];
int n,L;

ll solve(ll current,ll sum){
	if(current==n or sum == 3) return 0;
	
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	
	ll ans = max(solve(current+1,0),max(solve(current+1,sum+1)+D[current],solve(current+(3-sum),0)+D[current+(3-sum)]));
	return dp[current][sum] = ans;

}

main(){
	int z;
	cin >> z;
	
	for(int i=0;i<z;i++){
		memset(dp,-1,sizeof dp);
		memset(D,0,sizeof D);
		cin >> n >> L;
		
		for(int j=0;j<n;j++){
			cin >> D[j];
		}
		cout << solve(0,0) << endl;
	}
}
