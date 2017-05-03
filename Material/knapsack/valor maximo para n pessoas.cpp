#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n,m;
int produtos[1010][2],P[110];
ll dp[1010][30];
inline ll solve(ll current, ll w){
	
	if(current<0 or w <= 0) return 0LL;
	
	if(dp[current][w]!=-1) return dp[current][w];
	
	ll ans;
	if(produtos[current][1]<=w)
		ans = solve(current-1,w-produtos[current][1])+produtos[current][0];
		
	ans = max(solve(current-1,w),ans);
			
	return dp[current][w] = ans;
}

main(){
	int t;
	
	scanf("%d",&t);
	
	for(int k=0;k<t;k++){
	
		scanf("%d",&n);
		
		for(int i=0;i<n;i++){
			scanf("%d %d",&produtos[i][0], &produtos[i][1]);
		}
		
		scanf("%d",&m);
		memset(dp,-1,sizeof dp);
		ll ans = 0;
		for(int i=0;i<m;i++){
			scanf("%d",&P[i]);
			ans += solve(n-1,P[i]);
		}
		printf("%lld\n",ans);
	}
}
