#include <bits/stdc++.h>

using namespace std;

typedef int ll;
vector<vector<pair<int,int> > > Grafo(10100);
int n,m,a,b,from,to;

inline ll dijkstra(int ini,int fim){
	
	priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
	ll dist[n+1];
	for(int i=0;i<=n;i++) dist[i] = 10000000;
	pq.push(make_pair(0,ini));
	dist[ini] = 0;
	
	while(!pq.empty()){
		ll d = pq.top().first;
		ll v = pq.top().second;
		pq.pop();
		
		if(v == fim)
			return d;
			
		for(int i=0;i<Grafo[v].size();i++){
			if(dist[Grafo[v][i].first] > d + Grafo[v][i].second){
				pq.push(make_pair(d+Grafo[v][i].second,Grafo[v][i].first));
				dist[Grafo[v][i].first] = d+Grafo[v][i].second;
			}
		}
	}
	
	return -1;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m >> a >> b){	
		for(int i=0;i<=n;i++)
			Grafo[i].clear();
		
		for(int i=0;i<m;i++){
			cin >> from >> to;
			Grafo[from].push_back(make_pair(to,0));
			Grafo[to].push_back(make_pair(from,1));
		}
		ll ans1 = dijkstra(a,b);
		ll ans2 = dijkstra(b,a);
		if(ans1 == -1 or ans2 == -1 or ans1 == ans2){
			cout << "Bibibibika" << endl;
		}
		else{
			if(ans1 < ans2)
				cout << "Bibi: " << ans1 << endl;
			else
				cout << "Bibika: " << ans2 << endl;
		}
	}
}
