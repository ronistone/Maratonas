#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;

vector<int> Grafo[50001];
int Cartas[50001];
bool visitados[50001];
int n;
ll bfs(int ini,int dest){
	ll maior = 0;
	queue<ii> q;
	for(int i=0;i<Grafo[ini].size();i++){
		q.push(make_pair(1,Grafo[ini][i]));
	}
	
	cout << "bfs\n";
	visitados[ini] = true;
	while(!q.empty()){
		ll custo = q.front().first;
		int v = q.front().second;
		q.pop();
		
		for(int i=0;i<Grafo[v].size();i++){
			if(Cartas[Grafo[v][i]]==dest and maior < custo){
				cout << "Troca " << Cartas[Grafo[v][i]] << " " <<  custo+1 << endl;
				maior = custo+1;
			}
			if(!visitados[Grafo[v][i]] and Cartas[Grafo[v][i]]!=dest){
				q.push(make_pair(custo+1,Grafo[v][i]));
				visitados[Grafo[v][i]] = true;
			}
		}
			
	}
	
	
	return maior;	
}

main(){
	int i,j,k,aux,from,to;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> aux;
		Cartas[i]=aux;
		Grafo[i].clear();
	}
	for(i=0;i<n-1;i++){
		cin >> from >> to;
		Grafo[from-1].push_back(to-1);
		Grafo[to-1].push_back(from-1);
	}
	ll saida = 0;
	for(i=0;i<n;i++){
		memset(visitados,false,sizeof visitados);
		saida += bfs(i,Cartas[i]);
		Cartas[i] = -i;
	}
	cout << saida << endl;
}
