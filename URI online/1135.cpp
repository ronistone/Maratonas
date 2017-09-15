#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define TAM 18
typedef long long int ll;

vector<vector<int> > Grafo(100100);
ll lca[100100][TAM],parent[100100],dist[100100],nivel[100100];

inline void scanint(int *x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
inline void printint(int n)
{
	if(n == 0)
	{
		putchar_unlocked('0');
		putchar_unlocked('\n');
	}
	else if(n == -1)
	{
		putchar_unlocked('-');
		putchar_unlocked('1');
		putchar_unlocked('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while(n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while(buf[i] != '\n')
			putchar_unlocked(buf[++i]);
	}
}


void build_lca(int u, int v){
	parent[u] = v;
	dist[u]   = dist[v] + dist[u];
	nivel[u]  = nivel[v] + 1;
	lca[u][0] = v;
	
	for(int i=1;i<TAM;i++){
		lca[u][i] = lca[lca[u][i-1]][i-1]; 
	}
	for(int i=0;i<Grafo[u].size();i++){
		if(Grafo[u][i]!=v)
			build_lca(Grafo[u][i],u);
	}
}

int get_lca(int u, int v){
	
	if(nivel[u] > nivel[v])
		swap(u,v);
	
	int d = nivel[v] - nivel[u];
	
	for(int i=0;i<TAM;i++){
		if(d & (1<<i))
			v = lca[v][i];
	}
	
	if(u==v) return u;
	
	for(int i= TAM-1;i>=0;i--){
		if(lca[u][i]!=lca[v][i]){
			u = lca[u][i];
			v = lca[v][i];
		}
	}
	
	return lca[u][0];
}


main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n,from,to,w,q;
	while(cin >> n and n){
		dist[0] = 0;
		parent[0] = 0;
		nivel[0] = 0;
		for(int i=0;i<n;i++){
			Grafo[i].clear();
		}
		for(int i=1;i<n;i++){
			//cin >> to >> w;
			scanint(&to);
			scanint(&w);
			dist[i] = w;
			Grafo[i].pb(to);
			Grafo[to].pb(i);
		}
		build_lca(0,0);
		//cin >> q;
		scanint(&q);
		
		for(int i=0;i<q;i++){
			//cin >> from >> to;
			scanint(&from);
			scanint(&to);
			if(i!=0)
				cout << " ";
			cout << (dist[from]+dist[to]-2*dist[get_lca(from,to)]);
		}
		cout << endl;
	}
	

}
