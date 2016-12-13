#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > grafo;
vector<bool> visitados;
vector<int> idades,posicao;
int idade;

void dfs(int n){
	if(visitados[n] == false){
			for(int i =0;i<grafo[n].size();i++){
					if(idades[posicao[grafo[n][i]-1]]<idade)
						idade = idades[posicao[grafo[n][i]-1]];
					dfs(posicao[grafo[n][i]-1]);
			}
	}
}

main(){
	int i,j,k,e,from,to,in,out;
	int v,a,ins;
	char op;
	vector<int>aux;
	
	while(cin >> v >> a >> ins){
			for(i=0;i<v;i++){
				cin >> e;
				idades.push_back(e);
				grafo.push_back(aux);
				posicao.push_back(i);
				visitados.push_back(false);
			}
			for(i=0;i<a;i++){
					cin >> from >> to;
					grafo[to].push_back(from);
			}
			for(i=0;i<ins;i++){
					cin >> op;
					if(op=='P'){
						cin >> e;
						idade = 2000;
						for(j=0;j<visitados.size();j++){ visitados[j] = false;}
							dfs(posicao[e-1]);
						if(grafo[posicao[e-1]].size() == 0)
							cout << "*" << endl;
						else
							cout << idade << endl;
					}
					else if(op=='T'){
							cin >> in >> out;
							aux = grafo[posicao[in-1]];
							grafo[posicao[in-1]] = grafo[posicao[out-1]];
							grafo[posicao[out-1]] = aux;
							e = idades[posicao[in-1]];
							idades[posicao[in-1]] = idades[posicao[out-1]];
							idades[posicao[out-1]] = e;
					}
			}
		
	}

}
