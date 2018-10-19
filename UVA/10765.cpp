#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 10101
#define N 10100

typedef long long int ll;
typedef vector<int> vi;

vi graph[N];
int dfs_num[N];
int dfs_low[N];
int dfs_parent[N];
int dfs_count;
int root_children;
int dfs_root;
int articulation_point[N];
bool visi[N];
map<pair<int,int>, bool> bridge;
int from,to,n,m;

void clear(){
	for(int i=0;i<n;i++){
		graph[i].clear();
		dfs_num[i] = dfs_low[i] = UNVISITED;
		dfs_parent[i] = i;
		articulation_point[i] = 0;// false;
	}
	bridge.clear();
	dfs_count = root_children = 0;
}

void solve(int u){
	dfs_num[u] = dfs_low[u] = dfs_count++;
	for(int i=0;i<graph[u].size();i++){
		int v = graph[u][i];
		if(dfs_num[v]==UNVISITED){
			dfs_parent[v] = u;
			if(u == dfs_root) root_children++;
			
			solve(v);
			
			if(dfs_low[v] >= dfs_num[u]){
				articulation_point[u]++;// = true;
			}
			if(dfs_low[v] > dfs_num[u]){
				bridge[make_pair(u,v)] = true;
				bridge[make_pair(v,u)] = true;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if( v != dfs_parent[u] ){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
	
}

bool ord(pair<int,int> a, pair<int,int> b){
	if(a.second > b.second) return true;
	if(a.second == b.second) return a.first < b.first;
	return false;
}

void dfs(int v){
	visi[v] = true;
	for(int i=0;i<graph[v].size();i++){
		if(!visi[graph[v][i]])
			dfs(graph[v][i]);
	}
}

main(){
	vector<pair<int,int> > a;
	while(cin >> n >> m and (n != 0 or m != 0)){
		clear();
		while(cin >> from >> to and (from != -1 and to != -1)){
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		int pidge_min = 0;
		for(int i=0;i<n;i++){
			if(dfs_num[i]==UNVISITED){
				dfs_root = i;
				root_children = 0;
				solve(i);
				pidge_min++;
				articulation_point[i] = (root_children > 1)? articulation_point[i]-1:0;
				//cout << "Root of Component: " << i << endl;
			}
		}
		//for(int i=0;i<n;i++){
			//a.push_back(make_pair(i, articulation_point[i] + pidge_min));
		//}
		//for(int i=0;i<n;i++)
			//cout << i << " -- " << articulation_point[i] + pidge_min << " num - low: " << dfs_num[i] << " - " << dfs_low[i] << endl;
		memset(visi,false,sizeof visi);
		ll ans,pidge;
		for(int u=0;u<n;u++){
			ans = pidge_min;
			if(articulation_point[u]){
				pidge = 0;
				visi[u] = true;
				for(int j=0;j<graph[u].size();j++){
					int v = graph[u][j];
					if(!bridge[make_pair(u,v)]){
						if(!visi[u]){
							dfs(v);
							pidge++;
						}
					}else{
						pidge++;
					}
				}
				ans += pidge;
			}
			a.push_back(make_pair(u, ans));
		}
		sort(a.begin(),a.end(), ord);
		for(int i=0;i<m;i++){
			cout << a[i].first << " " << a[i].second << endl;
		}
		cout << endl;
		a.clear();
	}


}
