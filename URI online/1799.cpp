#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,string> is;
typedef vector<is> vis;
map<string,vector<string> > Grafo;

int n,m;

inline ll dijkstra(string from, string to){

	//priority_queue<is, vis, greater<is> > pq;
	queue<is> q;
	unordered_map<string,bool> visi;
	
	q.push(make_pair(0,from));
	
	while(!q.empty()){
		ll dist = q.front().first;
		string v = q.front().second;
		q.pop();
		
		if(v==to)
			return dist;
		
		for(int i=0;i<Grafo[v].size();i++){
			if(!visi[Grafo[v][i]]){
				q.push(make_pair(dist+1,Grafo[v][i]));
				visi[Grafo[v][i]] =  true;
			}
		}
	
	}
	
	return -1;

}




main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string from,to;
	vector<string> aux;
	while(cin >> n >> m){
		
		for(int i=0;i<m;i++){
			cin >> from >> to;
			if(!Grafo.count(from))
				Grafo[from] = aux;
			if(!Grafo.count(to))
				Grafo[to] = aux;
			Grafo[from].push_back(to);
			Grafo[to].push_back(from);
		}
		cout << dijkstra("Entrada","*")+dijkstra("*","Saida") << endl;
	}
}
