#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second

vector<pair<double,double> > vertices;
vector<pair<double,pair<int,int> > > arestas;
int parent[505];
inline double calc(pair<double,double> a, pair<double,double> b){
	return sqrt(((a.F-b.F)*(a.F-b.F)) + ((a.S-b.S)*(a.S-b.S)));
}

int findset(int x){
	if(x!=parent[x])
		parent[x] = findset(parent[x]);
	return parent[x];
}
void UNION(int i,int j){
	parent[i] = parent[j];
}

double mst(){
	int pu,pv;
	double total = 0;
	sort(arestas.begin(),arestas.end());
	for(int i=0;i<arestas.size();i++){
		pu = findset(arestas[i].S.F);
		pv = findset(arestas[i].S.S);
		if(pu!=pv){
			total += arestas[i].F;
			UNION(pu,pv);
		}
	}
	return total;
}

main(){
	
	int n;
	double x,y;
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> x >> y;
			vertices.pb(mp(x,y));
			parent[i] = i;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				arestas.pb(mp(calc(vertices[i],vertices[j]),mp(i,j)));
			}
		}
		cout << fixed << setprecision(2) << mst() << endl;
		vertices.clear();
		arestas.clear();
	}
}
