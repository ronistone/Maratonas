#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > Grafo(105);
bool visitados[105];
vector<int> S;

void dfs(int n){
	visitados[n] = true;
	
	for(int i=0;i<Grafo[n].size();i++){
		if(!visitados[Grafo[n][i]])
			dfs(Grafo[n][i]);
	}
	S.push_back(n);
}

main(){
	int from,to,v,a,i,j;
	vector<int> aux;
	
	while(cin >> v >> a and (v + a)){
		memset(visitados, false, sizeof visitados);
		for(i=0;i<=v;i++){
			Grafo[i].clear();
		}
		for(i=0;i<a;i++){
			cin >> from >> to;
			Grafo[from].push_back(to);
		}
		for	(i=1;i<=v;i++){
			if(!visitados[i]){
				dfs(i);
			}
		}
		for(i=S.size()-1;i>=0;i--)
			cout << S[i] << " ";
		
		cout << endl;
		S.clear();
	}
}
