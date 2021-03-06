#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int,ii> > viii;
typedef long long int ll;
viii Grafo,MST;
vector<int> p;
int parent[200001];
ll total;
int findset(int x){
	if(x!=parent[x])
		parent[x] = findset(parent[x]);
	return parent[x];
}
void UNION(int x,int y){
	parent[x] = parent[y];
}
void kruskal(){
	int pu,pv;
	sort(Grafo.begin(),Grafo.end());
	for(int i=0;i<Grafo.size();i++){
		pu = findset(Grafo[i].second.first);
		pv = findset(Grafo[i].second.second);
		if(pu!=pv){
			total+=Grafo[i].first;
			UNION(pu,pv);
		}
		else
			p.push_back(Grafo[i].first);
		
	}

}
main(){
	int n,m,from,to,w;
	
	while(cin >> n >> m and n and m){
		Grafo.clear();
		ll t = 0;
		for(int i=0;i<m;i++){
			cin >> from >> to >> w;
			Grafo.push_back(make_pair(w,make_pair(from,to)));
			t+=w;
		}
		for(int i=0;i<n;i++){
			parent[i] = i;
		}
		total = 0;
		kruskal();
		if(p.size()!=0){
			for(int i=0;i<p.size();i++){
				if(i!=0)
					cout << " ";
				cout << p[i];
			}
		}
		else
			cout << "forest";
		cout << endl;
		p.clear();
	}
}
