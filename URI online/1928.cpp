#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

#define TAM 16
vector<vector<int> > Grafo(50010);
int nivel[50010], parent[50010];
int lca[50010][TAM], A[50010];

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
	nivel[u] = nivel[v] + 1;
	lca[u][0] = v;
	
	for(int i=1;i<TAM;i++){
		lca[u][i] = lca[lca[u][i-1]][i-1];
	}
	for(int i=0;i<Grafo[u].size();i++){
		if(Grafo[u][i]!=v){
			build_lca(Grafo[u][i],u);
		}
	}
}


int get_lca(int u, int v){
	
	if(nivel[u] > nivel[v])
		swap(u,v);
		
	int dist = nivel[v] - nivel[u];
	
	for(int i=0;i<TAM;i++){
		if(dist & (1<<i))
			v = lca[v][i];
	}
	
	if(u==v) return u;
	
	for(int j=TAM-1;j>=0;j--){
		if(lca[u][j]!=lca[v][j]){
			u = lca[u][j];
			v = lca[v][j];
		}
	}
	return lca[u][0];
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,from,to;
	map<int,pair<int,int> > M;
	//cin >> n;
	scanint(&n);
	
	for(int i=0;i<n;i++){
		//cin >> A[i];
		scanint(&A[i]);
		if(!M.count(A[i])) M[A[i]] = mp(i,-1);
		else 			   M[A[i]].S = i;
	}
	for(int i=0;i<n-1;i++){
		//cin >> from >> to;
		scanint(&from); scanint(&to);
		from--;to--;
		
		Grafo[from].pb(to);
		Grafo[to].pb(from);
	}
	nivel[1] = 0;
	parent[1] = 1;
	
	
	build_lca(1,1);
	int ans = 0;
	
	for(int i=1;i<=n/2;i++){
		from = M[i].F;
		to   = M[i].S;
		ans += (nivel[from] + nivel[to] - 2*nivel[get_lca(from,to)]);
	}
	printint(ans);
	//cout << ans << endl;
}
