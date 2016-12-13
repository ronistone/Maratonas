#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;

vvi Grafo(100001);
bool visitados[100001];
int n,m;
bool achou = false;
void dfs(int x){
	if(!achou){
		visitados[x] = true;
		for(int i=0;i<Grafo[x].size();i++){
			if(visitados[Grafo[x][i]){
				achou = true;
				break;
			}
				dfs(Grafo[x][i]);
		}
	}
}

int main(){
	int i,j,from,to;
	
	scanf("%d %d",&n,&m);
	
	for(i=0;i<m;i++){
		scanf("%d %d",&from,&to);
		Grafo[from-1].push_back(to-1);
	}
	for(i=0;i<n;i++){
		visitados.clear();
		dfs(i);
		if(visitados.size()==n){
			cout << "Bolada\n";
			return 0;
		}
	}
	cout << "Nao Bolada\n";
}
