#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > grafo;
vector<bool> visitados;
vector<char> gc,gd,cc;
void dfs(int n){
	if(visitados[n]==false){
		gc.push_back((char) n+97);
		for(int i=0;i<grafo[n].size();i++){
			visitados[n] = true;
			dfs(grafo[n][i]);
		}
	}
}

main(){
	int n,v,a;
	int i,j,k;
	char from,to;
	cin >> n;
	vector<int> aux;
	vector<vector<char> > saida;
	for(i=0;i<n;i++){
		cin >> v >> a;
		for(j=0;j<v;j++){
				grafo.push_back(aux);
				visitados.push_back(false);
		}
		for(j=0;j<a;j++){
				cin >> from >> to;
				grafo[(int)from-97].push_back((int)to-97);
				grafo[(int)to-97].push_back((int)from-97);
		}
		for(j=0;j<v;j++){
				gc.clear();
				dfs(j);
				if(gc.size()>0)
					saida.push_back(gc);
		}
		cout << "Case #" << i+1 << ":" << endl;
		for(j=0;j<saida.size();j++){
			sort(saida[j].begin(),saida[j].end());
			for(k=0;k<saida[j].size();k++)
				cout << saida[j][k] << ",";
			cout << endl;
		}
		cout << saida.size() << " connected components" << endl << endl;
		grafo.clear();
		saida.clear();
		visitados.clear();
	}
}
