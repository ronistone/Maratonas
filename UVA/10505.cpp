#include <bits/stdc++.h>
using namespace std;

#define EMPTY 1000
#define BLACK 1
#define RED 2
#define EXPLORED 1
#define VISITED 2
#define UNVISITED 0

int n;
vector<int> graph[300];
int visi[300];
int color[300];

void clear(){
	
	for(int i=0;i<300;i++){
		graph[i].clear();
		visi[i] = UNVISITED;
		color[i] = EMPTY;
	}
	
}

void read(){
	int to;
	int m;
	cin >> n;
	clear();
	for(int i=1;i<=n;i++){
		cin >> m;
		for(int j=0;j<m;j++){
			cin >> to;
			graph[i].push_back(to);
			graph[to].push_back(i);
		}
	}

}

void dfs(int i){
	visi[i] = VISITED;
	for(int j=0;j<graph[i].size();j++){
		if(visi[graph[i][j]] != VISITED) dfs(graph[i][j]);
	}		
}

int solve(int s){
	queue<int> q;
	q.push(s);
	color[s] = BLACK;
	visi[s] = true;
	int vi, black = 0, red = 0;
	while(!q.empty()){
	
		int v = q.front();
		q.pop();
		if(v > n) continue;
		
		if(color[v] == BLACK) black++;
		if(color[v] == RED) red++;
		
		for(int i=0;i<graph[v].size();i++){
			vi = graph[v][i];
			if(color[vi]!=EMPTY and color[vi] == color[v]){
				 dfs(v);
				 black = 0;
				 red = 0;
				 while(!q.empty()) q.pop();
			}
			else if(visi[vi] == UNVISITED){
				q.push(vi);
				visi[vi] = EXPLORED;
				color[vi] = color[v] == BLACK? RED:BLACK;
			}
		}
	
	}
	return max(black,red);
}

main(){
	int ans,t;
	cin >> t;
	
	
	while(t--){
		
		read();
		ans = 0;
		for(int i=1;i<=n;i++){
			if(!visi[i])
				ans += solve(i);
		}
		cout << ans << endl;
		
	}	
}
