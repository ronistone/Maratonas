#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long int ll;
typedef pair<double,double> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;

bool visitados[100010];
vector<vi> Grafo(100010);
int n;

inline double bfs(){
	
	queue<pair<int,pair<int,double> > > q;
	
	q.push(mp(1,mp(0,1.0)));
	visitados[1] = true;
	
	double ans = 0.0;
	while(!q.empty()){
		int v = q.front().F;
		int d = q.front().S.F;
		double p = q.front().S.S;
		double num = 0;
		q.pop();
		for(int i=0;i<Grafo[v].size();i++){
			if(!visitados[Grafo[v][i]])
				num++;
		}
		if(!num){
			ans += p*d;
		}
		else{
			for(int i=0;i<Grafo[v].size();i++){
				if(!visitados[Grafo[v][i]]){
					q.push(mp(Grafo[v][i],mp(d+1,p*(1.0/num))));
					visitados[Grafo[v][i]] = true;
				}
			}
		}
	}
	
	return ans;
}


main(){
	int from, to;
	cin >> n;
	
	for(int i=0;i<n-1;i++){
		cin >> from >> to;
		Grafo[from].pb(to);
		Grafo[to].pb(from);
	}
	
	cout << fixed << setprecision(9) << bfs() << endl;
}
