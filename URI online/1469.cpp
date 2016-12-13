#include <bits/stdc++.h>
using namespace std;
vector<int> idades;
vector<vector<int> > grafoA;
vector<bool> visitados;
int idade;
vector<int>posicao;
void dfsI(int n){
		if(visitados[n]==false){
			visitados[n] = true;
				for(int i=0 ;i<grafoA[n].size();i++){
						if(idades[posicao[grafoA[n][i]]-1]<idade)
							idade = idades[posicao[grafoA[n][i]]-1];
						dfsI(posicao[grafoA[n][i]]-1);
				}
		}
}



main(){
	int v,a,ins,from,to,id;
	int i,j,k,aux,b1,b2;
	vector<int> aux1;
	char O;
	
	while(cin >> v >> a >>ins){
			for(i=0;i<v;i++){
					cin >> id;
					idades.push_back(id);
					//grafo.push_back(aux);
					grafoA.push_back(aux1);
					visitados.push_back(false);
					posicao.push_back(i+1);
			}
			for(i=0;i<a;i++){
					cin >> from >> to;
					//grafo[from-1].push_back(to-1);
					grafoA[to-1].push_back(from-1);
			}
			for(i=0;i<ins;i++){
					cin >> O;
					if(O=='P'){
							cin >> b1;
							for(j=0;j<visitados.size();j++)visitados[j]= false;
							if(grafoA[posicao[b1-1]-1].size()==0)
								cout << "*" << endl;
							else{
								idade = idades[posicao[b1-1]-1];
								dfsI(posicao[b1-1]-1);
								cout << idade << endl;
							}
					}
					else if(O=='T'){
							cin >> b1 >> b2;
							//grafoA[b1-1].swap(grafoA[b2-1]);
							id = idades[posicao[b1-1]-1];
							idades[posicao[b1-1]-1] = idades[posicao[b2-1]-1];
							idades[posicao[b2-1]-1] = id;
							//vector<int> ax;
							//ax = grafoA[posicao[b1-1]-1];
							//grafoA[posicao[b1-1]-1] = grafoA[posicao[b2-1]-1];
							//grafoA[posicao[b2-1]-1] = ax;
							id = posicao[b1-1];
							posicao[b1-1] = posicao[b2-1];
							posicao[b2-1] = id;
					}
			}
			for(i=0;i<v;i++){
					cout << "Posição " << i+1 << "idade: " << idades[i] << "posicao " << posicao[i] << endl;
			}
	}
	
}
