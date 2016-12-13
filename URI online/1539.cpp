#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define F first
#define S second
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ll,iii> iiii;
typedef vector<iii> viii;
viii Grafo;
ll dist[101];
bool visitados[101];

int n,m;

ll dista(int x1, int y1, int x2, int y2){
	return (ll)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

ll dijkstra(int ini,int dest){
	priority_queue<iiii> pq;
	for(int i=0;i<n;i++) dist[i] = 10000000;
	memset(visitados,false,sizeof(visitados));
	pq.push(MP(0,MP(ini,MP(Grafo[ini].S.F,Grafo[ini].S.S))));
	dist[ini] = 0;
	while(!pq.empty()){
		ll custo = pq.top().F;
		int x = pq.top().S.S.F;
		int y = pq.top().S.S.S;
		int posi = pq.top().S.F;
		pq.pop();
		visitados[posi] = true;
		for(int i=0;i<n;i++){
			int xf = Grafo[i].S.F;
			int yf = Grafo[i].S.S;
			ll d = dista(x,y,xf,yf);
			if(d < Grafo[posi].F and d+custo<=dist[i]){
				dist[i] = d+custo;
			}
			else
				continue;
			if(!visitados[i])
				pq.push(MP(d+custo,MP(i,MP(xf,yf))));
		}
		
	}
	
	if(dist[dest]==10000000)
		return -1;
	else
		return dist[dest];
}

main(){
	int x,y,w,i,j,from,to;

	while(cin >> n and n){
		
		for(i=0;i<n;i++){
			cin >> x >> y >> w;
			Grafo.push_back(MP(w,MP(x,y)));
		}
		cin >> m;
		for(i=0;i<m;i++){
			cin >> from >> to;
			cout << trunc(dijkstra(from-1,to-1)) << endl;
		}
		Grafo.clear();
	}
}
