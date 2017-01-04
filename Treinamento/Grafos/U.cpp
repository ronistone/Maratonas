#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int,ii> > viii;
viii Grafo,MST;
int parent[505];
int total;
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
			MST.push_back(Grafo[i]);
			UNION(pu,pv);
		}
	}

}
main(){
	int n,m,from,to,w;
	
	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> from >> to >> w;
		Grafo.push_back(make_pair(w,make_pair(from-1,to-1)));
	}
	for(int i=0;i<n;i++){
		parent[i] = i;
	}
	total = 0;
	kruskal();
	cout << total << endl;
}
