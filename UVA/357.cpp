#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
int moedas[] = {1,5,10,25,50};
ll dp[10][1000010];

inline ll solve(ll current,ll sum){
	
	if(sum==0) return 1LL;
	if(current < 0 or sum<0) return 0LL;
	
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ll ans = solve(current,sum-moedas[current])+solve(current-1,sum);
	
	return dp[current][sum] = ans;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,-1,sizeof dp);
	ll ans;
	while(scanf("%lld",&n)!=EOF){
		ans = solve(4,n);
		cout << "There " << (ans==1? "is only ":"are ") << ans << (ans==1? " way":" ways") << " to produce " << n << " cents change." << endl;
	}

}
