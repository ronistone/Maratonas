#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,string> is;
unordered_map<string,vector<string> > linguas,palavra;

ll dijkstra(string from,string to){		
	unordered_map<string,ll> dist;
	priority_queue< is,vector<is>,greater<is> > pq;
	
	for(int i=0;i<linguas[from].size();i++){
		pq.push(make_pair(linguas[from][i].size(),linguas[from][i]));
		dist[linguas[from][i]] = 0;
	}	
	while(!pq.empty()){
		string v = pq.top().second;
		ll D = pq.top().first;
		pq.pop();
		for(int i=0;i<palavra[v].size();i++){
			if(palavra[v][i] == to)
				return D;
		}
		for(int i=0;i<palavra[v].size();i++){
			string &p = palavra[v][i];
			for(int j=0;j<linguas[p].size();j++){
				string& aux = linguas[p][j];
				if((!dist.count(aux) or dist[aux] > D+aux.size()) and v[0]!=aux[0]){
					pq.push(make_pair(D+aux.size(),aux));
					dist[aux] = D+aux.size();
				}
			}
		}	
	}
	return -1;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string l1,l2,p1,from,to;
	vector<string> aux;
	int v;
	while(cin >> v and v){
		linguas.clear();
		palavra.clear();
		cin >> from >> to;
		for(int i=0;i<v;i++){
			cin >> l1 >> l2 >> p1;
			if(!linguas.count(l1))
				linguas[l1] = aux;
			linguas[l1].push_back(p1);
			if(!linguas.count(l2))
				linguas[l2] = aux;
			linguas[l2].push_back(p1);
			if(!palavra.count(p1))
				palavra[p1] = aux;
			palavra[p1].push_back(l1);
			palavra[p1].push_back(l2);
		}
		ll ans = dijkstra(from,to);
		if(ans == -1)
			cout << "impossivel" << endl;
		else
			cout << ans << endl;
	}
}
