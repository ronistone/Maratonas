#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<ll> vll;
vvii Grafo(1001);
int n,m;

bool ford(int ini){
	vll dist(n+1,LLONG_MAX);
	dist[ini] = 0;
	for(int i=0;i<n-1;i++){
		for(int k=0;k<n;k++){
			for(int j=0;j<Grafo[k].size();j++){
				ii v = Grafo[k][j];
				if(dist[k]!=LLONG_MAX)
				dist[v.first] = min(dist[v.first],dist[k]+v.second);
			}
		}
	}
//	bool negative = false;
	for(int i=0;i<n;i++){
		for(int j = 0;j<Grafo[i].size();j++){
			ii v = Grafo[i][j];
			if(dist[v.first]!=LLONG_MAX and dist[v.first] > dist[i]+v.second){
				return true;
			}
		}
	}
	return false;
}
void reset(){
	for(int i=0;i<n;i++){
		Grafo[i].clear();
	}
}

main(){
	int k,from,to,w,i,j;
	
	cin >> k;
	
	for(i=0;i<k;i++){
		cin >> n >> m;
		reset();
		for(j=0;j<m;j++){
			cin >> from >> to >> w;
			Grafo[from].push_back(make_pair(to,w));		
		}
		if(ford(0))
			cout << "possible\n";
		else
			cout << "not possible\n";
	}
}
