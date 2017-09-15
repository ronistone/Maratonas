#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<pair<ll,ll> > > Grafo(10010);
int parent[10005];
ll w[10005], from, to,ans = 0, we, n;
double cap;



void find_parent(int v, int p){
	parent[v] = p;
	for(int i=0;i<Grafo[v].size();i++){
		if(Grafo[v][i].first != p){
			find_parent(Grafo[v][i].first,v);
		}
	}
}
void dfs(int v, int p, int dist){
	
	for(int i=0;i<Grafo[v].size();i++){
		if(Grafo[v][i].first != p){
			dfs(Grafo[v][i].first,v,Grafo[v][i].second);
		}
	}
	ans += ceil(double(w[v]/cap))*2*dist;
	w[p] += w[v];
	w[v] = 0;
}


main(){
	
	cin >> n >> cap;
	w[0] = 0;
	for(int i=1;i<=n;i++){
		cin >> w[i];
		parent[i] = 0;
	}
	for(int i=1;i<=n-1;i++){
		cin >> from >> to >> we;
		Grafo[from].push_back(make_pair(to,we));
		Grafo[to].push_back(make_pair(from,we));
	}
	ans = 0;
	find_parent(1,1);
	dfs(1,1,0);
	
	cout << ans << endl;
}
