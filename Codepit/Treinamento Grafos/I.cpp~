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
bool articulation_tree[1005];
int dfsNumberCounter,Children,dfsRoot,n;
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
		if(dfs_num[v]==0){
			dfs_parent[v] = u;
			if(u==dfsRoot)
				Children++;
			dfs(v);
			
			if(dfs_low[v]>=dfs_num[u])
				articulation_tree[u] = true;
			if(dfs_low[v]>dfs_num[u])
				pontes.push_back(make_pair(min(u,v),max(u,v)));
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if(v!=dfs_parent[u])
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
	}	
}
void reset(){
	for(int i=0;i<n;i++){
			dfs_num[i] = 0;
			dfs_low[i] = 0;
			dfs_parent[i] = 0;
			articulation_tree[i] = false;
		}
		dfsNumberCounter =0;
}
void solve(){
	reset();
	for(int i=0;i<n;i++){
		if(dfs_num[i]==0){
			dfsRoot = i;
			Children = 0;
			dfs(i);
		}
		articulation_tree[dfsRoot] = (Children>1);
	}
	sort(pontes.begin(),pontes.end());
	print_dfs();
}

main(){
	int i,j,k,from,to,m;

	while(scanf("%d",&n)!=EOF){
		pontes.clear();
		for(i=0;i<n;i++){
			Grafo[i].clear();
		}
		for(i=0;i<n;i++){
			scanf("%d (%d)",&from,&m);
			for(j=0;j<m;j++){
				scanf("%d",&to);
				Grafo[from].push_back(to);
				Grafo[to].push_back(from);
			}
		}
		solve();
	}
}
