#include <bits/stdc++.h>
using namespace std;

#define UNVISITED -1010101
#define N 100100

typedef long long int ll;


map<int,vector<ll> > v_component;
map<pair<int,int>, bool> bridge;
int articulation_point[N];
vector<int> graph[N];
vector<ll> components_val;
vector<ll> components;
int parent[N];
int root_children;
int vertice_count;
bool visi[N];
int dfs_num[N];
int dfs_low[N];
int n,m;
int dfs_root;
int A[N];
int componentOf[N];


ll calc_component_val(int u){
	visi[u] = true;
	int v;
	ll ans = A[u];
	for(int i=0;i<graph[u].size();i++){
		v = graph[u][i];
		if(!visi[v])
			ans += calc_component_val(v);
	}
	return ans;
}

ll tarjan(int u){
	dfs_num[u] = dfs_low[u] = vertice_count++;
	componentOf[u] = components.size();
	ll component_val = A[u];
	for(int i=0;i<graph[u].size();i++){
		
		int v = graph[u][i];
		
		if( dfs_num[v] == UNVISITED ){
		
			parent[v] = u;
			
			if(u==dfs_root) root_children++;
			component_val += tarjan(v);
			
			if(dfs_low[v] >= dfs_num[u]){
				articulation_point[u]++;
				visi[u] = true;
				//v_component[u].push_back(calc_component_val(v));
				
				if(dfs_low[v] > dfs_num[u]){
					bridge[make_pair(u,v)] = true;
					bridge[make_pair(v,u)] = true;
				}
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);

		}else{
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
	return component_val;
}

void clear(){
	v_component.clear();
	bridge.clear();
	for(int i=0;i<=n;i++){
		dfs_low[i] = dfs_num[i] = UNVISITED;
		articulation_point[i] = 0;
		parent[i] = i;
		visi[i] = false;
		graph[i].clear();
		componentOf[i] = UNVISITED;
	}

}

main(){
	int from,to;
	ll ans = 0;
	cin >> n >> m;
	
	clear();
	
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	
	for(int i=0;i<m;i++){
		cin >> from >> to; from--; to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	for(int i=0;i<n;i++){
		if(dfs_num[i] == UNVISITED){
			dfs_root = i;
			root_children = 0;
			components.push_back(tarjan(i));
			
			if(root_children <= 1){
				articulation_point[i] = 0;
				v_component[i].clear();
			}
		}
	}
	int ansGet[n];
	memset(ansGet, false, sizeof ansGet);
	for(int i=0;i<components.size();i++){
		if(components[i] > 0){
			ans += components[i];
			ansGet[i] = true;
		}
	}
	
	for(int i=0;i<n;i++){
		if(articulation_point[i]){
			memset(visi, false, sizeof visi);
			visi[i] = true;
			for(int j=0;j<graph[i].size();i++){
				int v = graph[i][j];
				if(!visi[v]){
					v_component[i].push_back(calc_component_val(v));
				}
			}
		}
	}
	
	//for (int i=0;i<n;i++){
		//cout << "Vertex " << i << ": " << endl;
		//cout << "AP: " << articulation_point[i] << endl;
		//for(int j=0;j<v_component[i].size();j++){
			//cout << "value: " << v_component[i][j] << endl;
		//}
		//cout << endl << endl;
	//}
	
	int comp;
	ll localAns = 0;
	for(int i=0;i<n;i++){
		localAns = ans;
		comp = componentOf[i];
		
		if(ansGet[comp]){
			localAns -= components[comp];
		}
		
		if(articulation_point[i]){
			
			for(int j=0;j<v_component[i].size();j++){
				localAns += v_component[i][j]>0? v_component[i][j]:0;
			}
			
		}else{
			localAns += max(components[comp] - A[i], 0LL);
		}
		if(i > 0){
			cout << " ";
		}
		cout << localAns;
			
	}
	cout << endl;
	
	
	
}
