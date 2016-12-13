#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
vvi Grafo(1005);
vii pontes;
int dfs_low[1005];
int dfs_num[1005];
int dfs_parent[1005];
bool articulation_vertex[1005];
int dfsNumberCounter,Children,dfsRoot,n,arti;
void print_dfs(){
	cout << pontes.size() << " critical links\n";
	for(int i=0;i<pontes.size();i++){
		cout << pontes[i].first << " - " << pontes[i].second << "\n";
	}
	cout << "\n";
}
void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int i=0;i<Grafo[u].size();i++){
		int v = Grafo[u][i];
		if(dfs_num[v]==-1){
			dfs_parent[v] = u;
			if(u==dfsRoot)
				Children++;
			dfs(v);
			
			if(dfs_low[v]>=dfs_num[u]){
				articulation_vertex[u] = true;}
//			if(dfs_low[v]>dfs_num[u])
//				pontes.push_back(make_pair(u,v));
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if(v!=dfs_parent[u])
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
	}	
}
void reset(){
	for(int i=0;i<n;i++){
			Grafo[i].clear();
			dfs_num[i] = -1;
			dfs_low[i] = 0;
			dfs_parent[i] = 0;
			articulation_vertex[i] = false;
		}
		//pontes.clear();
		dfsNumberCounter = 0;
		arti = 0;
}
void solve(){
	for(int i=0;i<n;i++){
		if(dfs_num[i]==-1){
			dfsRoot = i;
			Children = 0;
			dfs(i);
			articulation_vertex[i] = (Children>1);
		}
	}
	for(int i=0;i<n;i++){
		if(articulation_vertex[i])
			arti++;
	}
	cout << arti << "\n";
}

main(){
	int i,j,k,from,to,m;

	while(cin >> n and n){
		reset();
		for(i=0;i<n+1;i++){
			cin >> from;
			if(from==0)
				break;
			while(cin >> to and to){
				Grafo[from-1].push_back(to-1);
				Grafo[to-1].push_back(from-1);
				if(getchar()=='\n')
					break;
			}
		}
		solve();
	}
}
