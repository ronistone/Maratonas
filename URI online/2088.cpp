#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
pair<double,double> pontos[510];
vector<pair<double,pair<int,int> > > arestas;
int parent[510];


inline double calcD(int i,int j){
	return sqrt((pontos[i].F - pontos[j].F)*(pontos[i].F - pontos[j].F) + (pontos[i].S - pontos[j].S)*(pontos[i].S - pontos[j].S));
}
inline int findset(int x){
	if(x!=parent[x])
		parent[x] = findset(parent[x]);
	return parent[x];
}
inline void UNION(int x,int y){
	parent[x] = parent[y];	
}
inline double kruskal(){
	int pu,pv;
	double ans = 0;
	sort(arestas.begin(),arestas.end());
	for(int i=0;i<arestas.size();i++){
		pu = findset(arestas[i].S.F);
		pv = findset(arestas[i].S.S);
		if(pu!=pv){
			ans += arestas[i].F;
			UNION(pv,pu);
		}
	}
}


main(){
	int n;
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> pontos[i].F >> pontos[i].S;
			parent[i] = i;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j)
					arestas.pb(mp(calcD(i,j),mp(i,j)));
			}
		}
		double ans = kruskal();
		cout << fixed << setprecision(2) << ans << endl;
		arestas.clear();
	}
	


}
