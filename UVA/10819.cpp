#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long int ll;

int n,w;
pair<int,int> P[110];
ll dp[110][11000];

inline bool ord(pair<int,int> a, pair<int,int> b){
	return a.F < b.F;
}

inline ll solve(ll current,ll peso){

	if(current >= n or peso > (peso>2000?w+200:w)) return 0LL;
	
	if(dp[current][peso]!=-1) return dp[current][peso];
	
	ll ans;
	//ll sum = w - peso;
	if(P[current].F+peso <= w or (peso+P[current].F > 2000 and peso+P[current].F <= w+200))
		ans = max(solve(current+1,peso + P[current].F)+P[current].S, solve(current+1, peso));
	else
		ans = solve(current+1, peso);
	
	return dp[current][peso] = ans;
	
}

main(){
	
	while(scanf("%d %d",&w,&n)!=EOF){
			
		for(int i=0;i<n;i++){
			scanf("%d %d",&P[i].F, &P[i].S);
		}
		sort(P,P+n,ord);
		memset(dp,-1,sizeof dp);
		printf("%lld\n",solve(0,0));
	}
	
	

}
