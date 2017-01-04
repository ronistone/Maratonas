#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
vvi Grafo(2005);
bool visitados[2005];
int n,m;
void dfs(int n){
	visitados[n] = true;
	for(int i=0;i<Grafo[n].size();i++){
		if(!visitados[Grafo[n][i]])
			dfs(Grafo[n][i]);
	}
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,z,from,to,way;
	
	while(cin >> n >> m and n and m){
		for(j=0;j<n;j++){Grafo[j].clear();}
		for(j=0;j<m;j++){
			cin >> from >> to >> way;
			Grafo[from-1].push_back(to-1);
			if(way==2)
				Grafo[to-1].push_back(from-1);
		}
		bool falha = false;
		for(j=0;j<n;j++){
			memset(visitados,false,sizeof(visitados));
			dfs(j);
			for(int k=0;k<n;k++){if(visitados[k]==false){falha = true;break;}}
			if(falha)
				break;
		}
		if(falha)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}

}
