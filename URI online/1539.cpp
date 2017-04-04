#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-15
typedef int ll;
ll n,m;
typedef struct no{
	int x,y,d;
	no(int x_,int y_,int d_): x(x_), y(y_), d(d_) {}
	no() {}
}antena;
typedef pair<double,ll> ii;
antena at[110];
inline double dista(antena a ,antena b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline ll dijkstra(int ini, int fim){
	double dist[n+1];
	for(int i=0;i<=n;i++) dist[i] = 100000000.0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(make_pair(0.0,ini));
	dist[ini] = 0.0;
	while(!pq.empty()){
		double d = pq.top().first;
		ll v = pq.top().second;
		pq.pop();	
		if(v == fim) return trunc(d);
		for(int i=0;i<n;i++){
			double aux = dista(at[v],at[i]);
			if(aux < at[v].d and (d+aux) < dist[i]){
				dist[i] = d+aux;
				pq.push(make_pair(aux+d,i));
			}
		}
	}
	return -1;
}

inline void scanint(ll *x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
inline void printint(ll n)
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
main(){
	int x,y,d,from,to;
	scanint(&n);
	while(n){
		for(int i=0;i<n;i++){
			scanint(&x);scanint(&y);scanint(&d);
			at[i] = antena(x,y,d);
		}
		scanint(&m);
		for(int i=0;i<m;i++){
			scanint(&from);scanint(&to); from--;to--;
			printint(dijkstra(from,to));
		}
		scanint(&n);
	}
}

