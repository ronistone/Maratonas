#include <bits/stdc++.h>
using namespace std;

vector<pair<double,double> > vertices;
vector<pair<double,pair<double,double> > > arestas;
int parent[505];

inline double calc(pair<double,double> a, pair<double,double> b){
	return sqrt(((a.first - b.first)*(a.first - b.first)) + ((a.second - b.second)*(a.second - b.second)));
}
inline int findset(int x){
	if(x != parent[x])
		return parent[x] = findset(parent[x]);
	return parent[x];
}
inline void UNION(int x,int y){
	parent[x] = parent[y];
}

inline double kruskal(){
	int pv,pu;
	double total = 0;
	sort(arestas.begin(),arestas.end());
	for(int i=0;i<arestas.size();i++){
		pv = findset(arestas[i].second.first);
		pu = findset(arestas[i].second.second);
		if(pv!=pu){
			total += arestas[i].first;
			UNION(pv,pu);
		}
	}
	return total;
}


main(){
	ios_base::sync_with_stdio(0);
	int z,n;
	double x,y;
	cin >> z;
	
	for(int k=0;k<z;k++){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			vertices.push_back(make_pair(x,y));
			parent[i] = i;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				arestas.push_back(make_pair(calc(vertices[i],vertices[j]),make_pair(i,j)));
			}
		}
		cout << fixed << setprecision(2) << kruskal()/100 << endl;
		arestas.clear();
		vertices.clear();
	}


}
