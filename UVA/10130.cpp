#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

/*ll n,m;
ll produtos[1100][2];
ll P[110];

ll dp[1100][110][50];
ll solve(ll current,ll at,ll w){
		
	if(current>=n or at>=m or w <= 0) return 0LL;
	if(dp[current][at][w]!=-1) return dp[current][at][w];
	
	ll ans = 0LL;
	
	if(produtos[current][1] <= w){
		ans = max(solve(current+1,at,w - produtos[current][1])+produtos[current][0],
				  max(solve(current+1,at+1,P[at+1])+produtos[current][0],
					  solve(current,at+1,P[at+1])+produtos[current][0])
			  );
	}
	ans = max(solve(current+1,at,w),
			max(solve(current,at+1,P[at+1]),
				max(solve(current+1,at+1,P[at+1]),ans))
		  );

	return dp[current][at][w] = ans;
}


main(){
	int t;
	
	cin >> t;
	
	for(int k=0;k<t;k++){
		
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> produtos[i][0] >> produtos[i][1];
		}
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> P[i];
		}
		memset(dp,-1,sizeof dp);
		cout << solve(0,0,P[0]) << endl;
	
	}

}
*/

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
