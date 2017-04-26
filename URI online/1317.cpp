#include <bits/stdc++.h>
using namespace std;

int n,t1,t2;
string a1,a2,a3;
string A[30];
vector<vector<int> > Grafo(30);

void bfs(int ini){
	
	queue<int> q;
	bool visi[n];
	memset(visi,false,sizeof visi);
	q.push(ini);
	visi[ini] = true;
	while(!q.empty()){
		
		int at = q.front();
		q.pop();
		for(int i=0;i<Grafo[at].size();i++){
			if(!visi[Grafo[at][i]]){
				q.push(Grafo[at][i]);
				visi[Grafo[at][i]] = true;
			}
		}
		int D = Grafo[at].size();
		if(D < t1)
			A[at] += a1 + " ";
		else if(D < t2)
			A[at] += a2 + " ";
		else
			A[at] += a3 + " ";
	}
	for(int i=0;i<n;i++){
		if(!visi[i])
			A[i] += a1 + " ";
	}
}



main(){
	int aux;
	while(cin >> n){
		for(int i=0;i<n;i++){
			 Grafo[i].clear();
			 A[i].clear();
		}
		
		for(int i=0;i<n;i++){
			while(cin >> aux and aux){
				aux--;
				Grafo[i].push_back(aux);
			}
		}
		
		while(cin >> aux and aux){
			aux--;
			cin.ignore();
			cin >> t1 >> t2 >> a1 >> a2 >> a3;
			bfs(aux);
		}
		for(int i=0;i<n;i++){
			cin.ignore();
			cin >> a1;
			cout << a1 << ": " << A[i] << endl;
		}
	}
	

}
