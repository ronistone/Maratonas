#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
vvi Grafo(10005);
//vii pontes;
vector<vector<int> >pontes(10005);
bool visitados[10005];
int dfs_low[10005];
int dfs_num[10005];
int dfs_parent[10005];
bool articulation_tree[10005];
int dfsNumberCounter,Children,dfsRoot,n,P;

void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int i=0;i<Grafo[u].size();i++){
		int v = Grafo[u][i];
		if(dfs_num[v]==0){
			dfs_parent[v] = u;
			//if(u==dfsRoot)
			//	Children++;
			dfs(v);
			
			//if(dfs_low[v]>=dfs_num[u])
			//	articulation_tree[u] = true;
			if(dfs_low[v]>dfs_num[u]){
				int z = u>v ? v:u;
				int pa = u<v ? v:u;
				//pontes.push_back(make_pair(min(u,v),max(u,v)));
				pontes[z].push_back(pa);
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
		else if(v!=dfs_parent[u])
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
	}	
}
bool bfs(int ini,int dest){
	queue<int> q;
	int z,pa;
	q.push(ini);
	visitados[ini] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x==dest)
			return true;
		for(int i=0;i<Grafo[x].size();i++){
			if(!visitados[Grafo[x][i]]){
				z = Grafo[x][i]>x ? x:Grafo[x][i];
				pa = Grafo[x][i]<x ? x:Grafo[x][i];
				if(find(pontes[z].begin(),pontes[z].end(),pa)!=pontes[z].end()){
					visitados[Grafo[x][i]] = true;
					q.push(Grafo[x][i]);
				}
			}
		}
	}
	return false;
}

void reset(){
	for(int i=0;i<n;i++){
			Grafo[i].clear();
			pontes[i].clear();
			dfs_num[i] = 0;
			dfs_low[i] = 0;
			//dfs_parent[i] = 0;
			//articulation_tree[i] = false;
		}
		dfsNumberCounter =0;
}
void resetV(){
	for(int i=0;i<n;i++)
		visitados[i]=false;
}
void solve(int t){
	int ini,dest;
	for(int i=0;i<n;i++){
		if(dfs_num[i]==0){
			//dfsRoot = i;
			//Children = 0;
			dfs(i);
			//articulation_tree[dfsRoot] = (Children>1);
		}
	}
	for(int i=0;i<t;i++){
		cin >> ini >> dest;
		resetV();
		if(bfs(ini-1,dest-1))
			printf("Y\n");
		else
			printf("N\n");
	}
	puts("-");
	//sort(pontes.begin(),pontes.end());
	//print_dfs();
}

main(){
	int i,j,k,from,to,m,t;

	while(scanf("%d %d %d",&n,&m,&t) and (n or m or t)){
		reset();
		for(i=0;i<m;i++){
			scanf("%d %d",&from,&to);
			Grafo[from-1].push_back(to-1);
			Grafo[to-1].push_back(from-1);
		}
		
		solve(t);
	}
}
