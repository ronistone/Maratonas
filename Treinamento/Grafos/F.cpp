#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo(305);
int cores[305];
bool visitados[305];
int n,m;

bool bfs_bi(){
	memset(visitados,false,sizeof(visitados));
	memset(cores,-1,sizeof(cores));
	queue<int> F;
	F.push(0);
	cores[0] = 0;
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
		for(i=0;i<n;i++){Grafo[i].clear();}
		while(scanf("%d %d",&from,&to) and from and to){
			Grafo[from-1].push_back(to-1);
			Grafo[to-1].push_back(from-1);
		}
		if(bfs_bi())
			printf("YES\n");
		else
			printf("NO\n");
	}

}
