#include <bits/stdc++.h>
using namespace std;

map<pair<int,pair<int,int> >,int> id;
vector<vector<pair<int,int> > > Grafo(1000100);
typedef long long int ll;
vector<int> corte;
bool visitado[1000100];
ll vertices[1000100];

ll solve(int current){
	ll temp = 0, ans = 0;	
	visitado[current] = true;
	for(int i=0;i<Grafo[current].size();i++){
		if(!visitado[Grafo[current][i].first]){
			temp = solve(Grafo[current][i].first)+Grafo[current][i].second;
			ans += temp;
			if(ans - temp  > ans){
			//	corte.push_back(id[make_pair(current,Grafo[current][i])]);
				ans -= temp;
				vertices[Grafo[current][i].first] = -10000000000000000;
			}
		}
	}
	return vertices[current] = ans;
}
void print(int current){
		visitado[current] = true;
		for(int i=0;i<Grafo[current].size();i++){
			if(vertices[Grafo[current][i].first] == -10000000000000000){
				corte.push_back(id[make_pair(current,Grafo[current][i])]);
			}
			else if(!visitado[Grafo[current][i].first]){
				print(Grafo[current][i].first);
			}
		}
}

main(){
	int n;
	int idi,from,to,w;
	cin >> n;
		memset(visitado,0,sizeof visitado);
		for(int i=0;i<n;i++)
			Grafo[i].clear();
		id.clear();
		corte.clear();
		memset(vertices,0,sizeof vertices);
		for(int i=0;i<n-1;i++){
			cin >> idi >> from >> to >> w;
			Grafo[from].push_back(make_pair(to,w));
			Grafo[to].push_back(make_pair(from,w));
			id[make_pair(from,Grafo[from][Grafo[from].size()-1])] = idi;
			id[make_pair(to,Grafo[to][Grafo[to].size()-1])] = idi;
		}
		//dfs(0,0);
		//memset(visitado,0,sizeof visitado);
		ll ans = solve(0);
		memset(visitado,0,sizeof visitado);
		print(0);
		cout << ans << " " << corte.size() << endl;
		if(corte.size()){
			sort(corte.begin(),corte.end());
			for(int i=0;i<corte.size();i++){
				if(i!=0)
					cout << " ";
				cout << corte[i];
			}
			cout << endl;
		}
}
