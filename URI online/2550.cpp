#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo(1010);
bool visi[1010];
int parent[1010];
vector<pair<int,pair<int,int> > > vertices;
typedef int ll;
int n,m,cont,from,to;

void UNION(int x, int y){
	parent[x] = parent[y];
}
int find(int x){
	if(parent[x]!=x)
		return parent[x] = find(parent[x]);
	return parent[x];
}
void dfs(int c){
	visi[c] = true;
	cont--;
	for(int i=0;i<Grafo[c].size();i++)
		if(!visi[Grafo[c][i]])
			dfs(Grafo[c][i]);
}


ll kruskal(){
	sort(vertices.begin(),vertices.end());
	int u,v;
	ll ans = 0;
	for(int i=0;i<vertices.size();i++){
		u = find(vertices[i].second.first);
		v = find(vertices[i].second.second);
		if(u!=v){
			UNION(u,v);
			ans += vertices[i].first;
			Grafo[vertices[i].second.first].push_back(vertices[i].second.second);
			Grafo[vertices[i].second.second].push_back(vertices[i].second.first);
		}
	}
	dfs(from);
	if(cont!=0)
		return -1;
	return ans;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int w;
	
	while(cin >> n >> m){
		for(int i=0;i<=n;i++){
			Grafo[i].clear();
			visi[i] = false;
			parent[i] = i;
		}
		vertices.clear();
		for(int i=0;i<m;i++){
			cin >> from >> to >> w;
			vertices.push_back({w,{from,to}});
			vertices.push_back({w,{to,from}});
		}
		cont = n;
		ll ans = kruskal();
		if(ans!=-1)
			cout << ans << endl;
		else
			cout << "impossivel" << endl;
	}

}
