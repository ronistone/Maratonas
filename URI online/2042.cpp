#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long int ll;
typedef pair<ll,pair<ll,int> > iii;  // (Gasto,Ganho,Next)

int n,m,from,to,w;
vector<vector<iii> > Grafo(105);
ll dp[105][10100];

ll solve(ll current,ll sola){
	if(sola < 0 or current >= n) return -10101010101010;
	if(current == to) return 0LL;
	
	if(dp[current][sola]!=-1) return dp[current][sola];
	
	ll ans = LLONG_MIN;
	
	for(int i=0;i<Grafo[current].size();i++)
		ans = max(ans, solve(Grafo[current][i].S.S,sola-Grafo[current][i].F)+Grafo[current][i].S.F);
	
	return dp[current][sola] = ans;
}



main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int fr,t,p,g;
	
	while(cin >> n >> m and n and m){
		for(int i=0;i<n;i++)
			Grafo[i].clear();
		
		cin >> from >> to; from--; to--;
		
		cin >> w;
		
		for(int i=0;i<m;i++){
			cin >> fr >> t >> g >> p; fr--; t--;
			Grafo[fr].pb(mp(p,mp(g,t)));
			Grafo[t].pb(mp(p,mp(g,fr)));
		}
		memset(dp,-1,sizeof dp);
		ll ans = solve(from,w);
		if(ans < 0)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}

}
