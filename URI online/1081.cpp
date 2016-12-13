#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo;
vector<bool> visitados;
int v;

void dfs(int n,int cont){
	visitados[n] = true;
	for(int i=0;i<Grafo[n].size();i++){
		for(int j=0;j<cont;j++)
				cout << "  ";
		if(visitados[Grafo[n][i]]==false){
				printf("%d-%d pathR(G,%d)\n",n,Grafo[n][i],Grafo[n][i]);
				dfs(Grafo[n][i],cont+1);
		}
		else
			cout << n << "-" << Grafo[n][i] << endl;
	}
}

main(){
	int n,a,from,to,aux;
	int i,j,k;
	vector<int> A;
	
	cin >> n;
	
	for(i=0;i<n;i++){
		cin >> v >> a;
		for(j=0;j<v;j++){
			Grafo.push_back(A);
			visitados.push_back(false);
		}
		for(j=0;j<a;j++){
			cin >> from >> to;
			if(find(Grafo[from].begin(),Grafo[from].end(),to)==Grafo[from].end())
			Grafo[from].push_back(to);
		}
		for(j=0;j<v;j++)
			sort(Grafo[j].begin(),Grafo[j].end());
		cout << "Caso " << i+1 << ":" << endl;
		bool entrou = false;
		for(j=0;j<v;j++){
			if(visitados[j]==false and Grafo[j].size()>0){
				if(entrou)
					cout << endl;
				dfs(j,1);
				entrou = true;
			}
		}
		cout << endl;
		Grafo.clear();
		visitados.clear();
	}
}
