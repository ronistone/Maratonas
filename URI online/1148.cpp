#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,int> ii;
typedef vector<ii> vii;

int Grafo[501][501];
ll dist [501];
int n,m;

ll dijkstra(int ini,int dest){
	priority_queue<ii,vii,greater<ii> > pq;
	pq.push(make_pair(0,ini));
	for(int i=0;i<n;i++) dist[i] = 1000000000;
	while(!pq.empty()){
		ll custo = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		for(int i =0;i<n;i++){
			if(custo+Grafo[v][i] < dist[i] and Grafo[v][i]!=-1){
				dist[i] = custo+Grafo[v][i];
				pq.push(make_pair(custo+Grafo[v][i],i));
			}
		}
	}
	if(dist[dest]==1000000000)
		return -1;
	else
		return dist[dest];
}

void reset(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Grafo[i][j] = -1;
		}
	}

}

main(){
	int i,j,from,to,w,z;
	ll d;	
	while(cin >> n >> m and n and m){
		reset();
		for(i=0;i<m;i++){
			cin >> from >> to >> w;
			if(Grafo[to-1][from-1]!=-1){
				Grafo[from-1][to-1] = 0;
				Grafo[to-1][from-1] = 0;
			}
			else
				Grafo[from-1][to-1] = w;
		}
		cin >> z; 
		for(i=0;i<z;i++){
			cin >> from >> to;
			if(Grafo[from-1][to-1]==0 and Grafo[to-1][from-1]==0 or from==to)
				cout << 0 << endl;
			else{
				d = dijkstra(from-1,to-1);
				if(d==-1)
					cout << "Nao e possivel entregar a carta\n";
				else
					cout << d << endl;
			}
		}
			cout << endl;
	
	}
}
