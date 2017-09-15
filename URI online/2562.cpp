#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo(1005);
bool visitados[1005];


int dfs(int n){
	visitados[n] = true;
	int ans = 1;
	for(int i=0;i<Grafo[n].size();i++){
		if(!visitados[Grafo[n][i]])
			ans += dfs(Grafo[n][i]);
	}
	return ans;
}


main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,m,from,to;
		
		while(cin >> n >> m){
			for(int i=0;i<=n;i++) Grafo[i].clear();
			memset(visitados,false,sizeof visitados);
			for(int i=0;i<m;i++){
				cin >> from >> to;
				Grafo[from].push_back(to);
				Grafo[to].push_back(from);
			}
			cin >> from;
			cout << dfs(from) << endl;
		}

}
