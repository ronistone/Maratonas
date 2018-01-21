#include <bits/stdc++.h>
using namespace std;

#define TAM 25
#define F first
#define S second
typedef int ll;
vector<pair<ll,pair<int,int> > > V;
vector<vector<pair<ll,int> > > Grafo(20010);
int parent[20010],lca[20010][TAM], pMAX[20010][TAM],nivel[20010];
int from,to,w,n,m,s,root;

int findSet(int u){
	if(u!=parent[u]) return parent[u] = findSet(parent[u]);
	return parent[u];
}
void UNION(int u, int v){
	parent[u] = parent[v];
}

vector<pair<ll,pair<int,int> > > kruskal(){
	sort(V.rbegin(),V.rend());
	int pu,pv;
	vector<pair<ll,pair<int,int> > > ans;
	for(int i=0;i<V.size();i++){
		pu = findSet(V[i].S.F);
		pv = findSet(V[i].S.S);
		
		if(pu!=pv){
			ans.push_back(V[i]);
			UNION(pu,pv);
			root = pu;
		}
	}
	return ans;
}

void clear(){
	for(int i=0;i<=n;i++){
		Grafo[i].clear();
		parent[i] = i;
		for(int j=0;j<TAM;j++)
			pMAX[i][j] = INT_MAX;
	}
	V.clear();
}

void build_lca(int u, int v,int w){
	
	parent[u] = v;
	nivel[u] = nivel[v] + 1;
	pMAX[u][0] = w;
	lca[u][0] = v;
	
	for(int i=1;i<TAM;i++){
		lca[u][i] = lca[lca[u][i-1]][i-1];
		pMAX[u][i] = min(pMAX[u][i-1], pMAX[lca[u][i-1]][i-1]);
	}
		
	for(int i=0;i< Grafo[u].size();i++){
		if(Grafo[u][i].F!=v)
			build_lca(Grafo[u][i].F,u,Grafo[u][i].S);
	}
}

ll query(int u, int v){
	
	if(nivel[u] > nivel[v])
		swap(u,v);
		
	ll dist = nivel[v] - nivel[u];
	int ans=INT_MAX;	
	
	for(int i=0;i<TAM;i++){
		if(dist & (1 << i)){
			ans = min(ans,pMAX[v][i]);
			v = lca[v][i];
		}
	}
	
	if(u==v)
		return ans;
		
	for(int i=TAM-1;i>=0;i--){
		if(lca[u][i]!=lca[v][i]){
			ans = min(ans,min(pMAX[u][i],pMAX[v][i])); 
			u = lca[u][i]; v = lca[v][i];
		}
	}
	
	return min(ans,min(pMAX[u][0],pMAX[v][0]));
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n >> m >> s){
		clear();
		for(int i=0;i<m;i++){
			cin >> from >> to >> w;
			V.push_back(make_pair(w,make_pair(from,to)));
		}
		V = kruskal();
		
		for(int i=0;i<V.size();i++){
			Grafo[V[i].S.F].push_back(make_pair(V[i].S.S,V[i].F));
			Grafo[V[i].S.S].push_back(make_pair(V[i].S.F,V[i].F));
		}
		parent[root] = 1;
		nivel[root] = 0;
		build_lca(root,root,INT_MAX);
		
		
		for(int i=0;i<s;i++){
			cin >> from >> to;
			
			cout << query(from,to) << endl;
		}
	
	}

}
