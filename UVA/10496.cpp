#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long int ll;

ll dp[12][1 << 12];
pair<ll,ll> M[12];
ll A[12][12];
ll n;
inline ll calc(int i,int j){
	return abs(M[i].F - M[j].F) + abs(M[i].S-M[j].S);
}
inline ll solve(int current,int mask){
	if(mask == (1 << n)-1) return A[current][0];
	if(dp[current][mask]!=-1) return dp[current][mask];
	
	ll ans = 1000000000;
	for(int i=0;i<n;i++){
		if(!(mask & 1 << i))
			ans = min(ans, solve(i,mask | (1 << i))+A[current][i]);
	}
	return dp[current][mask] = ans;
}

main(){
	int z,x,y;
	cin >> z;
	for(int i=0;i<z;i++){
		cin >> x >> y;
		cin >> M[0].F >> M[0].S;
		cin >> n; n++;
		for(int i=1;i<n;i++){
			cin >> M[i].F >> M[i].S;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				A[i][j] = calc(i,j);
			}
		}
		memset(dp,-1,sizeof dp);
		cout << "The shortest path has length " << solve(0,1) << endl;
	}

}
