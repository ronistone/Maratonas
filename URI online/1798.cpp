#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

pair<int,int> A[1010];
ll dp[1010][3000];
int n,m,w;

ll solve(int C,int P){
	if(C >= n or P <= 0) return P<0?LLONG_MIN:0LL;
	if(dp[C][P]!=-1) return dp[C][P];
	
	ll ans = max(solve(C,P-A[C].F)+A[C].S,solve(C+1,P));
	
	return dp[C][P] = ans;
}


main(){

	cin >> n >> w;
	
	for(int i=0;i<n;i++){
		cin >> A[i].F >> A[i].S;
	}
	memset(dp,-1,sizeof dp);
	
	cout << solve(0,w) << endl;

}
