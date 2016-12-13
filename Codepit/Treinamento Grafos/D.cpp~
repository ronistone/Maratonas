#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo(10005);
vector<pair<int,int> > Tropas(10005);
bool visitados[10005];
int Grau[10005];
int Refens[10005];
int n,m,s;
bool kahn(){
	int i;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > F;
	for(i=0;i<n;i++){
		if(Grau[i]==0){
			F.push(Tropas[i]);
		}
	}
	if(F.empty())
		return false;
	while(!F.empty()){
		pair<int,int> aux = F.top();
		if(s<=aux.first)
			return false;
		s+=Refens[aux.second];
		visitados[aux.second] = true;
		F.pop();
		for(i=0;i<Grafo[aux.second].size();i++){
			if(--Grau[Grafo[aux.second][i]]==0){
				F.push(Tropas[Grafo[aux.second][i]]);
			}
		}
	}
	for(i=0;i<n;i++){if(!visitados[i]) return false;}
	return true;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i;
	int from,to,aux;
	while(cin >> n >> m >> s and (n or m or s)){
		for(i=0;i<n;i++){
			Grau[i]=0;
			cin >> aux;
			Tropas[i] = make_pair(aux,i);
			Grafo[i].clear();
			visitados[i]=false;
		}
		for(i=0;i<n;i++){
			cin >> Refens[i];
		}
		for(i=0;i<m;i++){
			cin >> from >> to;
			Grafo[from-1].push_back(to-1);
			Grau[to-1]++;
		}
		bool a = kahn();
		if(!a)
			cout << "impossivel" << endl;
		else
			cout << "possivel" << endl;
	}
}
