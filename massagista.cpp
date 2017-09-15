#include <bits/stdc++.h>
using namespace std;

vector<pair<double,pair<double,double> > > arestas;
int parent[505];


inline int findset(int x){
	if(x!=parent[x])
		return parent[x] = findset(parent[x]);
	return parent[x];
}
inline void UNION(int x,int y){
	parent[x] = parent[y];
}

inline double kruskal(){
	double total = 0;
	int pu, pv;
	sort(arestas.rbegin(),arestas.rend());
	for(int i=0;i<arestas.size();i++){
		pu = findset(arestas[i].second.first);
		pv = findset(arestas[i].second.second);
		if(pu!=pv){
			total += arestas[i].first;
			UNION(arestas[i].second.first,arestas[i].second.second);
			
		}
	}
	return total;
}




main(){
	int n;
	cin >> n;
	
	

}
