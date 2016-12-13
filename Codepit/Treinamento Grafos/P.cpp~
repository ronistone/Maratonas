#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<pair<ll,ii> > vllii;
typedef pair<int,ii > iii;
typedef pair<ll,ii> llii;
bool g[105][105];
bool visitados[10][105];
int n;
ll dist[10][105];
int tempo[10];
int maior;
ll dijkstra(int ini,int dest){
	priority_queue<llii,vllii,greater<llii> > atual;
	memset(visitados,false,sizeof(visitados));
	for(int i=0;i<n;i++){for(int j=0;j<=maior;j++){dist[i][j]=LLONG_MAX;}}
	for(int i=0;i<n;i++){
		if(g[i][ini]){
			atual.push(make_pair(0,make_pair(i,ini)));
		}
	}
	while(!atual.empty()){
		ll custo = atual.top().first;
		int E = atual.top().second.first;
		int andar = atual.top().second.second;
		atual.pop();
		
		if(andar==dest)
			return custo;
		if(custo >= dist[E][andar])
			continue;
		dist[E][andar] = custo;
		visitados[E][andar] = true;
		for(int i = 0;i<=maior;i++){
			if(!visitados[E][i] and g[E][i]) //and (custo+tempo[E]*abs(i-andar)) < dist[E][i])
				atual.push(make_pair((custo+(tempo[E] * abs(i-andar))),make_pair(E,i)));
		}
		for(int i = 0;i<n;i++){
			if(!visitados[i][andar] and g[i][andar]) //and custo+60 < dist[i][andar])
				atual.push(make_pair((custo+60),make_pair(i,andar)));
		}
	}
return -1;	
}
main(){
	int i,j,k,from,to,peso,ini,dest,t;
	while(scanf("%d %d",&n,&dest)!=EOF){
		maior = -1;
		for(i=0;i<n;i++){
			scanf("%d",&tempo[i]);
		}
		memset(g,false,sizeof(g));
		for(i=0;i<n;i++){
			while(scanf("%d",&to)!=EOF){
					g[i][to] = true;
					if(to>maior)
						maior = to;
				if(getchar()=='\n')
					break;
			}
		}
		if(dest<=maior){
			ll saida = dijkstra(0,dest);
			if(saida!=-1)
				printf("%lld\n",saida);
			else
				printf("IMPOSSIBLE\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
}

