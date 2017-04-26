#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SC1(n) scanf("%d",&n)
#define SC2(n,m) scanf("%d %d",&n,&m)
#define SC3(n,m,z) scanf("%d %d %d",&n,&m,&z)
#define F1(i,n) for(i=1;i<=n;i++)
#define F2(i,n,m) for(i=n;i<m;i++)
#define MAX 10e5
typedef long long int ll;
int n,m,k;

vector<vector<int> > Grafo(510);
int idade[510],pessoa[510],vertice[510];

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

int bfs(int from){
	queue<int> q;
	bool visi[n];
	memset(visi,false,sizeof visi);
	
	q.push(from);
	visi[from] = true;
	int ans = MAX,i,V;
	int aux = idade[vertice[from]];
	idade[vertice[from]] = MAX;
	
	
	while(!q.empty()){
		V = q.front();
		q.pop();
		ans = min(idade[vertice[V]],ans);
		for(i=0;i<Grafo[V].size();i++){
			if(!visi[Grafo[V][i]]){
				q.push(Grafo[V][i]);
				visi[Grafo[V][i]] = true;
			}
		}
		
	}
	idade[vertice[from]] = aux;
	if(ans == MAX)
		return -1;
	else
		return ans;
}

main(){
	int i,j,aux,from,to,ans;
	char C;
	while(SC1(n)!=EOF){
		scanint(&m);scanint(&k);
		F1(i,n){
			scanint(&aux);
			Grafo[i].clear();
			idade[i] = aux;
			pessoa[i] = i;
			vertice[i] = i;
		}
		
		F1(i,m){
			scanint(&from);scanint(&to);
			Grafo[to].pb(from);
		}
		F1(i,k){
			scanf("%c",&C);
			scanint(&from);
			if(C=='P'){
				ans = bfs(pessoa[from]);
				if(ans==-1)
					printf("*\n");
				else
					printint(ans);
			}
			else{
				scanint(&to);
				aux = pessoa[from];
				pessoa[from] = pessoa[to];
				pessoa[to] = aux;
				vertice[pessoa[from]] = from;
				vertice[pessoa[to]] = to;
			}
		}
	
	}

}
