#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second


typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

vi vertices(3100,0);
vvi grafo(3100);
ll n,m;
ll at;
bool visitados[3100];
bool terminou;

bool verifica(){
	for(int i=0;i<n;i++){
		if(!visitados[i])
			return false;
	}
	return true;
}
/*
void dfs(ll n,ll p,ll ant){
	if(!visitados[n] and !terminou){
		visitados[n] = true;
		if(p%3==0 and p!=0){
			at++;
			p = 0;
		}
		vertices[n] = at;
		terminou = verifica();
		for(int i=0;i<grafo[n].size();i++){
			if(grafo[n][i]!=ant and !visitados[grafo[n][i]])
				dfs(grafo[n][i],p+1,n);
		}
	}
	at = vertices[n];
}
*/
void bfs(){
	queue<ii> q;
	q.push(mp(0,0));
	
	while(!q.empty()){
		ll v = q.front().S;
		ll d = q.front().F;
		q.pop();
		visitados[v] = true;
		vertices[v] = d < 3? 1:(d/3)+1;
		for(ll i=0;i<grafo[v].size();i++){
			if(!visitados[grafo[v][i]]){
				q.push(mp(d+1,grafo[v][i]));
			}	
		}
		
		
	}
	
	
}

void reset(){
	for(ll i=0;i<n;i++){
			grafo[i].clear();
			vertices[i] = 0;
			visitados[i] = false;
	}
	at = 1;
	terminou = false;
}

main(){
	ll t;
	ll from,to;
	
	cin >> t;
	
	for(ll k=0;k<t;k++){
		
		cin >> n >> m;
		reset();
		for(ll i=0;i<m;i++){
			cin >> from >> to;
			from--;
			to--;
			grafo[from].pb(to);
			grafo[to].pb(from);
		}
		//dfs(0,0,0);
		bfs();
		for(ll i=0;i<n;i++){
			cout << vertices[i] << endl;
		}
		cout << endl;
	}
}
