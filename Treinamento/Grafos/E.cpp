#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo(205);
int cores[205];
bool visitados[205];
int n,m;

bool bfs_bi(){
	memset(visitados,false,sizeof(visitados));
	memset(cores,-1,sizeof(cores));
	queue<int> F;
	F.push(0);
	cores[0] = false;
	while(!F.empty()){
		int aux = F.front();
		F.pop();
		if(!visitados[aux]){
			visitados[aux] = true;
			for(int i=0;i<Grafo[aux].size();i++){
				if(cores[Grafo[aux][i]]==-1)
					cores[Grafo[aux][i]] = 1-cores[aux];
				else if(cores[Grafo[aux][i]]==cores[aux])
					return false;
				cores[Grafo[aux][i]] = 1-cores[aux];
				F.push(Grafo[aux][i]);
			}
		}
	}
	return true;
}

main(){
	int i,j,aux,from,to;
	
	while(scanf("%d",&n) and n){
		cin >> m;
		for(i=0;i<n;i++){Grafo[i].clear();}
		for(i=0;i<m;i++){
			scanf("%d %d",&from,&to);
			Grafo[from].push_back(to);
		}
		if(bfs_bi())
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

}
