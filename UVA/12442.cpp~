#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<int,int> vii;

vvi Grafo(50001);
vi Visitados(50001);

void dfs(int n){
	Visitados[n] = true;
	for(int i=0;i<Grafo[n].size();i++){
		if(!Visitados[Grafo[n][i]]){
			dfs(Grafo[n][i]);
		}
	}
}

main(){
	int n,m,i,j,saida,from,to;
	bool f;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&m);
		for(j=0;j<m;j++){Grafo[j].clear(); Visitados[j] = false;}
		for(j=0;j<m;j++){
			scanf("%d %d",&from,&to);
			Grafo[from-1].push_back(to-1);
		}
		for(j=0;j<m;j++){
			if(!Visitados[j]){
				dfs(j);
			}
			f = false;
			for(int k=0;k<m;k++){
				if(Visitados[k]==false){
					f = true;
					break;
				}
			}
			if(!f){
				printf("Case %d: %d\n",i+1,j+1);
				break;
			}
		}
	}
}
