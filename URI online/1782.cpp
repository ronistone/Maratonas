#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool visi[100100];
vector<vector<pair<int,int> > > Grafo(100010);
vector<pair<int,pair<int,int> > > vertices;
int num;
int dfs(int v, int p){
	for(int i=0;i<Grafo[v].size();i++){
		if(Grafo[v][i].second!=p)
			return dfs(Grafo[v][i].second,v);
	}
	return v;
}
int dfs1(int v, int p, int w){
	num++;
	visi[v] = true;
	for(int i=0;i<Grafo[v].size();i++){
		if(!visi[Grafo[v][i].second] and Grafo[v][i].first <= w)
			return dfs1(Grafo[v][i].second,v,w);
	}
	return v;
}


ll solve(int v, int limit){
	int ini = dfs(v,v);
	ll ans = 0;
	bool achou;
	while(true){
		num = 0;
		ini = dfs1(ini,ini,limit);
		ans += (num*(num-1))/2;
		achou = false;
		for(int i=0;i<Grafo[ini].size();i++){
			if(!visi[Grafo[ini][i].second]){
				ini = Grafo[ini][i].second;
				achou = true;
				break;
			}
		}
		if(!achou) break;
	}
	return ans;
}



main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,from,to,w,q,j;
	
	cin >> t;
	
	for(int k=0;k<t;k++){
		cin >> n;
		vertices.clear();
		//for(int i=0;i<=100000;i++)
			//Grafo[i].clear();
		
		for(int i=0;i<n-1;i++){
			cin >> from >> to >> w;
			vertices.push_back(make_pair(w,make_pair(from,to)));
			//Grafo[from].push_back(make_pair(w,to));
			//Grafo[to].push_back(make_pair(w,from));
			Grafo[from].clear();
			Grafo[to].clear();
		}
		for(int i=0;i<vertices.size();i++){
			Grafo[vertices[i].second.first].push_back(make_pair(vertices[i].first,vertices[i].second.second));
			Grafo[vertices[i].second.second].push_back(make_pair(vertices[i].first,vertices[i].second.first));
		}
		cin >> q;
		cout << "Caso #" << k+1 << ":";
		for(int i=0;i<q;i++){
			cin >> j;
			memset(visi,false,sizeof visi);
			cout << " " << solve(from,j)+n;
		}
		cout << endl;
	}
}
