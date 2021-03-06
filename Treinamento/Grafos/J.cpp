#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef pair<int,int> ii;
vvi Grafo(100001);
bool visitados[100001];
vector<bool> visi;
stack<int> ordem;
int n,m;
void dfs(int n){
	visitados[n] = true;
	for(int i=0;i<Grafo[n].size();i++){
		if(!visitados[Grafo[n][i]])
			dfs(Grafo[n][i]);
	}
}
void dfsOrd(int n){
	visitados[n] = true;
	for(int i=0;i<Grafo[n].size();i++){
		if(!visitados[Grafo[n][i]])
			dfs(Grafo[n][i]);
	}
	ordem.push(n);
}
void reset(){
	for(int i=0;i<n;i++)
		visitados[i]=false;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	int i,j,z,from,to;
	cin >> z;
	
	for(i=0;i<z;i++){
		cin >> n >> m;
		for(j=0;j<n;j++)
			Grafo[j].clear();
		for(j=0;j<m;j++){
			cin >> from >> to;
			Grafo[from-1].push_back(to-1);
		}
		reset();
		
		for(j=0;j<n;j++){
			if(!visitados[j])
				dfsOrd(j);
		}
		reset();
		int cont = 0;
		while(!ordem.empty()){
			int x = ordem.top();
			ordem.pop();
			if(!visitados[x]){
				dfs(x);
				cont++;
			}
		}
		cout << cont << endl;
	}

}
