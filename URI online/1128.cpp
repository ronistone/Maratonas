#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;

vvi Grafo(2001);
bool visitados[2001];
int n,m;

void dfs(int x){
	visitados[x] = true;
	for(int i=0;i<Grafo[x].size();i++){
		if(!visitados[Grafo[x][i]])
			dfs(Grafo[x][i]);
	}	
}
void reset(){
	for(int i=0;i<n;i++)
		visitados[i]=false;
}

main(){
	int i,j,from,to,mao;
	
	while(cin >> n >> m and n and m){
		for(i=0;i<n;i++){
			Grafo[i].clear();
		}
		for(i=0;i<m;i++){
			cin >> from >> to >> mao;
			Grafo[from-1].push_back(to-1);
			if(mao==2)
				Grafo[to-1].push_back(from-1);
		}
		bool falha =false;
		for(i=0;i<n and !falha;i++){
			reset();
			dfs(i);
			for(j=0;j<n;j++){
				if(!visitados[j]){
					falha = true;
					break;
				}
			}
		}
		cout << !falha << "\n";
	}
}
