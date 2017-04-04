#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll sum;
int n;
int A[200];
ll dp[200][100000];

inline ll solve(ll current,ll at){
	if(current>=n) return abs(at-(sum-at));
	if(dp[current][at]!=-1) return dp[current][at];
	
	ll ans = min(solve(current+1,at+A[current]),solve(current+1,at));
	
	return dp[current][at] = ans;
}
main(){
	ll k;
	cin >> k;
	
	for(int x = 0;x<k;x++){
		scanf("%d",&n);
		sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
			sum += A[i];
		}
		memset(dp,-1,sizeof dp);
		printf("%lld\n",solve(0,0));
	}

}
