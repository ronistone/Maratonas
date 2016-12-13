#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > grafo;
vector<bool> visitados;
int ini,contador;

int dfs(int inicio){
        int total = 0;
        visitados[inicio] = true;
            for(int i=0;i<grafo[inicio].size();i++){
				if(!visitados[grafo[inicio][i]]){
                    total += dfs(grafo[inicio][i]) +  1;
				}
			}
	return total;
}

main(){
    int n,v,a,aux,aux1;
    int i,j,k;
    vector<int> abc;
    
    cin >> n;
   
    for(i=0;i<n;i++){
            cin >> ini;
            cin >> v >> a;
            for(j=0;j<v;j++){
                    grafo.push_back(abc);
                    visitados.push_back(false);
            }
            for(j=0;j<a;j++){
                    cin >> aux >> aux1;
                    grafo[aux].push_back(aux1);
                    grafo[aux1].push_back(aux);
            }
          
            cout << dfs(ini)*2 << endl;
            grafo.clear();
            abc.clear();
            visitados.clear();
       
    }
   
}
