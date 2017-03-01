#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef struct no{
	int x,y;
	int idade;
	no(int x_,int y_,int i_): x(x_),y(y_),idade(i_){}
	no(){}
}V;
typedef pair<ll,V> llV;
vector<V> Grafo(101000);
int n;

inline ll bfs(){	
	queue<llV> Q;
	Q.push(mp(0,V(0,0,0)));
	ll ans = -1;
	while(!Q.empty()){
		V temp = Q.front().S;
		ll d = Q.front().F;
		Q.pop();
		if(d>ans)
			ans = d;
		for(int i=temp.idade;i<n;i++){
			if(Grafo[i].idade > temp.idade and Grafo[i].x >= temp.x and Grafo[i].y >= temp.y)
				Q.push(mp(d+1,Grafo[i]));
		}
		
	}
	return ans;
}


main(){
	int x,y,t;
	
	scanf("%d",&t);
	
	for(int k=0;k<t;k++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			Grafo[i] = V(x,y,i+1);
		}
		printf("%lld\n",bfs());
	}
}
