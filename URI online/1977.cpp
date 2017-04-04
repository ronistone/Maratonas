#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,string> is;
map<string,vector<is> > Grafo;
ll n,v,x;

ll dijkstra(string from,string to){
	map<string,ll> dist;
	priority_queue<is, vector<is>, greater<is> > pq;
	if(x > 30)
		pq.push(make_pair(1070,from));
	else
		pq.push(make_pair(1050,from));
		
	dist[from] = 0;
	while(!pq.empty()){
	
		string vert = pq.top().second;
		ll p = pq.top().first;
		pq.pop();
		
		if(vert==to)
			return p;
			
		for(int i=0;i<Grafo[vert].size();i++){
			string &nxt = Grafo[vert][i].second;
			ll &nxtW = Grafo[vert][i].first;
			if(!dist.count(nxt) or (dist.count(nxt) and dist[nxt] > p+nxtW)){
				pq.push(make_pair(p+nxtW,nxt));
				dist[nxt] = p+nxtW;
			}
		}
	
	}
	
	return -1;
}


main(){
	string from,to;
	ll w;
	vector<is> aux;
	while(cin >> x >> n >> v and x and n and v){
		Grafo.clear();
		for(int i=0;i<n;i++){
			cin >> from >> to >> w;
			if(!Grafo.count(from))
				Grafo[from] = aux;
			Grafo[from].push_back(make_pair(w,to));
		}
		ll ans = dijkstra("varzea","alto");
		
		int h = ans/60;
		int m = ans%60;
		
		cout << h << ":";
		if(m < 10)
			cout << 0;
		cout << m << endl;
		if(h > 18 or (h == 18 and m > 0))
			cout << "Ira se atrasar\n";
		else
			cout << "Nao ira se atrasar\n";
	}


}
