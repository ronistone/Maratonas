#include <bits/stdc++.h>
using namespace std;

int n,m,q;
vector<int> graph[1010];
bool visi[1010];


typedef long long int ll;
ll dfs(int from, int to){
	visi[from] = true;
	if(from == to) return 1;
	
	ll  ans = 0;
	for(int i=0;i<graph[from].size();i++){
		if(!visi[graph[from][i]] or graph[from][i] == to)
			ans += dfs(graph[from][i],to);
	}
	return ans;
}

bool bfs(int from, int to){
	
	queue<int> q;
	
	q.push(from);
	int ans = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		
		if(v == to){
			 ans++;
			 if(ans > 1)
				return false;
		}
		else{
			for(int i=0;i<graph[v].size();i++){
				if(!visi[graph[v][i]] or graph[v][i] == to){
					q.push(graph[v][i]);
					visi[v] = true;
				}
			}
		}
	}
	return ans == 1;
}


int main(){
	int x,y;
	cin >> n >> m >> q;
	
	for(int i=0;i<m;i++){
		cin >> x >> y; x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	for(int i=0;i<q;i++){
		cin >> x >> y; x--;y--;
		memset(visi, false, sizeof(visi));
		//if(dfs(x,y) == 1)
		if(bfs(x,y))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	

	return 0;
}
