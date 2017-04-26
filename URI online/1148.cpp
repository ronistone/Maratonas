#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
vector<vector<int> > Grafo(505);
unordered_map<int,unordered_map<int,int> > arestas;
typedef long long int ll;
int n,m;

ll dijkstra(int from,int to){
	ll dist[n];
	unordered_map<int,int>::iterator it;
	for(int i=0;i<n;i++)
		dist[i] = 1010101010101010;
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
	
	pq.push(mp(0,from));
	dist[from] = 0;
	
	while(!pq.empty()){
		ll D = pq.top().F;
		int v = pq.top().S;
		pq.pop();
		
		if(v==to)
			return D;
		for(it=arestas[v].begin();it!=arestas[v].end();it++){
			
			if(D+it->second < dist[it->first]){
				pq.push(mp(D+it->second,it->first));
				dist[it->first] = D+it->second;
			}
		
		}
		
	}
	
	return -1;
}
inline void scanint(int *x)
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
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int from,to,w,q;
	bool first = true;
	while(true){
		scanint(&n);
		scanint(&m);
		if(!(n or m))
			break;
		//if(!first)
		for(int i=0;i<n;i++){
			Grafo[i].clear();
			arestas[i].clear();
		}
		arestas.clear();
		for(int i=0;i<m;i++){
			scanint(&from);scanint(&to);scanint(&w);
			from--;to--;
			Grafo[from].push_back(to);
			if(find(Grafo[to].begin(),Grafo[to].end(),from)!=Grafo[to].end()){
				arestas[from][to] = 0;
				arestas[to][from] = 0;
			}
			else{
				if(!arestas[from].count(to))
					arestas[from][to] = w;
				else
					arestas[from][to] = min(arestas[from][to],w);
			}
		}
		scanint(&q);
		for(int i=0;i<q;i++){
			scanint(&from);scanint(&to);
			from--;to--;
			ll ans = dijkstra(from,to);
			if(ans==-1)
				cout << "Nao e possivel entregar a carta" << endl;
			else
				printint(ans);
		}
//		first = false;
		cout << endl;
	}
}
