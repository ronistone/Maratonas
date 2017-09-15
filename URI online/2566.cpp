#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first

typedef long long int ll;
typedef pair<ll,ll> ii;
vector<vector<pair<ll,ii> > > Grafo(105);
ll n,m;

ll solve(ll from,ll to){
	
	ll dist[n+1];
	for(int i=0;i<=n;i++) dist[i] = 1010101010;
	priority_queue<pair<ll,ii>,vector<pair<ll,ii> >, greater<pair<ll,ii> > > pq;
	for(int i=0;i<Grafo[from].size();i++)
		pq.push({Grafo[from][i].S.S,{Grafo[from][i].F,Grafo[from][i].S.F}});
	dist[from] = 0;
	
	while(!pq.empty()){
		ll v = pq.top().S.F;
		ll w = pq.top().F;
		ll meio = pq.top().S.S;
		pq.pop();
		if(v == to)
			return w;
		for(int i=0;i<Grafo[v].size();i++){
			if(dist[Grafo[v][i].F] > w+Grafo[v][i].S.S and Grafo[v][i].S.F==meio)
				pq.push({w+Grafo[v][i].S.S,{Grafo[v][i].F,meio}});
		}
	}
	return -1;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll from,to,x,w;
	while(cin >> n >> m){
		for(int i=0;i<=n;i++){
			Grafo[i].clear();
		}
		for(int i=0;i<m;i++){
			cin >> from >> to >> x >> w;
			Grafo[from].push_back({to,{x,w}});
		}
		cout << solve(1,n) << endl;
	}

}
