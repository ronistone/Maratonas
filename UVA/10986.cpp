#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<pair<int,int> > > vvii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef pair<int,int> ii;
typedef long long ll;
vvii Grafo(20005);
bool visitados[20005];
int vertice,aresta;

ll dijkstra(int ini,int dest){
	long long dist[vertice];
	for(int i=0;i<vertice;i++){dist[i] = LLONG_MAX;}
	priority_queue<ii,vii,greater<ii> >pq;
	dist[ini] = 0;
	pq.push(make_pair(dist[ini],ini));
	
	while(!pq.empty()){
		ii p = pq.top();
		int u = p.second; 
		pq.pop();
		if(!visitados[u]){
			visitados[u] = true;
			for(int i=0;i<Grafo[u].size();i++){
				int v = Grafo[u][i].first;
				int custo = Grafo[u][i].second;
				if(dist[v] > (dist[u]+custo)){
					dist[v] = dist[u]+custo;
					pq.push(make_pair(dist[v],v));
				}
			}
		}
	
	}



	return dist[dest];
}

main(){
	int i,j,k,n,from,to,peso,ini,dest;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> vertice >> aresta >> ini >> dest;
		for(j=0;j<vertice;j++){Grafo[j].clear();visitados[j]=false;}
		for(j=0;j<aresta;j++){
			cin >> from >> to >> peso;
			Grafo[from].push_back(make_pair(to,peso));
			Grafo[to].push_back(make_pair(from,peso));
		}
		ll saida = dijkstra(ini,dest);
		if(saida!=LLONG_MAX)
			cout << "Case #" << i+1 << ": " << saida << endl;
		else
			cout << "Case #" << i+1 << ": unreachable" << endl;
	}
}
