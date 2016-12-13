#include <bits/stdc++.h>
using namespace std;

int n,m;
int aux;
int grafo[210][210];
int visitados[210][210];

void dfs(int i,int j,int valor){

	visitados[i][j] = true;
	
	if(i>0 && grafo[i-1][j] == valor and visitados[i-1][j]==false)
		aux++,dfs(i-1,j,valor);
	if(i<n-1 && grafo[i+1][j] == valor and visitados[i+1][j]== false)
		aux++,dfs(i+1,j,valor);
	if(j>0 && grafo[i][j-1] == valor and visitados[i][j-1]== false)
		aux++,dfs(i,j-1,valor);
	if(j<m-1 && grafo[i][j+1] == valor and visitados[i][j+1]==false)
		aux++,dfs(i,j+1,valor);
}

main(){
	int i,j,k,a;
	int menor = 20000000;
	
	cin >> n >> m;
	
	for(i=0;i<n;i++){
		memset(visitados[i],false,sizeof(visitados[i]));
			for(j=0;j<m;j++){
					cin >> a;
					grafo[i][j] = a;
			}
	}
	for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(visitados[i][j]==false){
					aux = 1;
					dfs(i,j,grafo[i][j]);
					if(aux<menor and aux!=0)
						menor = aux;
				}
			}
	}
	cout << menor << endl;
}
