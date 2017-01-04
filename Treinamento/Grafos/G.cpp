#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo(1005);
int cores[1005];
bool visitados[1005];
int n,m;

bool bfs_bi(){
	queue<int> F;
	F.push(0);
	cores[0] = 0;
	while(!F.empty()){
		int A = F.front();
		F.pop();
		for(int i=0;i<Grafo[A].size();i++){
			if(cores[Grafo[A][i]]!=-1 and cores[A]== cores[Grafo[A][i]])
				return false;
			else
				if(!visitados[Grafo[A][i]])
				cores[Grafo[A][i]] = 1-cores[A],F.push(Grafo[A][i]),visitados[Grafo[A][i]] = true;
		}
	}
	return true;
}

main(){
	int i,j,aux,from,to;
	
	scanf("%d",&n);
		for(i=0;i<n;i++){
			Grafo[i].clear();
			visitados[i] = false;
			cores[i] = -1;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&aux);
				if(aux==0)
					Grafo[i].push_back(j),Grafo[j].push_back(i);
			}
		}
		if(bfs_bi())
			printf("Bazinga!\n");
		else
			printf("Fail!\n");

}
