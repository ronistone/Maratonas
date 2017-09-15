#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > Grafo(101);
int z;
int visi[200];

bool bfs(){
	queue<pair<int,int> > q;
	q.push(make_pair(0,0));
	memset(visi,-1,sizeof visi);
	visi[0] = 0;
	
	while(!q.empty()){
		int v = q.front().first;
		int cor = q.front().second;
		q.pop();
		
		for(int i=0;i<Grafo[v].size();i++){
			if(visi[Grafo[v][i]]==-1){
				q.push(make_pair(Grafo[v][i],1-cor));
			}
			else if(visi[Grafo[v][i]]==cor){
				return false;
			}
			visi[Grafo[v][i]] = 1-cor;
		}
	}
	return true;
}


main(){
	int n,aux;
	stringstream ss;
	string e;
	while(cin >> z and z){
		for(int i=0;i<z;i++)
			Grafo[i].clear();
		for(int k=0;k<z;k++){
			cin >> n;
			cin.ignore();
			e.clear();
			ss.clear();
			getline(cin,e);
			ss << e;
			while(ss >> aux){
				aux--;
				Grafo[k].push_back(aux);
				Grafo[aux].push_back(k);
			}
		}
		if(bfs()){
			cout << "SIM" << endl;
		}
		else{
			cout << "NAO" << endl;
		}
	}


}
