#include <bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int> > Grafo;
unordered_map<int,bool> visi;
unordered_map<int,bool> vertices;
unordered_map<int,bool>::iterator it;


void bfs(int ini){
	queue<int> q;
	q.push(ini);
	
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i=0;i<Grafo[v].size();i++){
			if(!visi[Grafo[v][i]]){
				q.push(Grafo[v][i]);
				visi[Grafo[v][i]] = true;
			}
				
		}
	}
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,from,m,ans;
	vector<int> ansv;
	while(cin >> n and n){
	
		while(cin >> m and m){
			while(cin >> from and from){
				Grafo[m].push_back(from);
			}
		}
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> from;
			visi.clear();
			bfs(from);
			ans = 0;
			ansv.clear();
			for(int i=1;i<=n;i++){
				if(!visi[i]){
					ans++;
					ansv.push_back(i);
				}
					
			}
			cout << ans;
			for(int i=0;i<ansv.size();i++)
				cout << " " << ansv[i];
			cout << endl;
		}
		vertices.clear();
		Grafo.clear();
	}
}
