#include <bits/stdc++.h>
using namespace std;

vector<vector<string > > Grafo(105);
map<string,int> V;
map<int,string> S;
map<string,int> grau;
int n,m;
vector<int> saida;
void kahn(){
	int i;
	priority_queue<int> F;
	for(i=0;i<n;i++){
		if(grau[S[i]]==0)
			F.push(-i);
	}
	while(!F.empty()){
		int aux = -F.top();
		saida.push_back(aux);
		F.pop();
		for(i=0;i<Grafo[aux].size();i++){
			if(--grau[Grafo[aux][i]]==0)
				F.push(-V[Grafo[aux][i]]);
		}
	}

}


main(){
	int i,j,k,cont=1;
	string e,from,to;
	while(cin >> n){
		cin.ignore();
		for(i=0;i<n;i++){
			cin >> e;
			cin.ignore();
			V[e]=i;
			S[i]=e;
			Grafo[i].clear();
		}
		cin >> m;
		for(i=0;i<m;i++){
			cin >> from >> to;
			Grafo[V[from]].push_back(to);
			grau[to]++;
		}
		kahn();
		cout << "Case #" << cont << ": Dilbert should drink beverages in this order: ";
		for(i=0;i<saida.size();i++){
			cout << S[saida[i]];
			if(i!=saida.size()-1)
				cout << " ";
		}
		cout <<"." << endl;
		V.clear();
		S.clear();
		saida.clear();
		cont++;
		cout << endl;
	}
}
