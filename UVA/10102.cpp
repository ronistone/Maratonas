#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef pair<ll,iii> iiii;
typedef vector<ii> vii;
typedef vector<ll> vi;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char matriz[10005][10005];
vii ini;
int n;

bool valid(ii posi){
		if(posi.F<0 or posi.F>=n) return false;
		if(posi.S<0 or posi.S>=n) return false;
		return true;
}

ll bfs(){
		queue<iiii> q;
		bool calc[ini.size()];
		bool visi[n][n][ini.size()];
		memset(visi,false,sizeof visi);
		memset(calc,false,sizeof(calc));
		for(int i=0;i<ini.size();i++){
				q.push(mp(0,mp(i,ini[i])));
		}
		ll maior = 0;
		while(!q.empty()){
				ll custo = q.front().F;
				ll in = q.front().S.F;
				ii posi = q.front().S.S;
				q.pop();
				if(!calc[in]){
					if(matriz[posi.F][posi.S]=='3'){
						maior = max(maior,custo);
						calc[in] = true;
						continue;
					}
					for(int i=0;i<4;i++){
							ii aux = mp(posi.F+dx[i],posi.S+dy[i]);
							if(valid(aux) and !visi[aux.F][aux.S][in]){
								visi[aux.F][aux.S][in] = true;
								q.push(mp(custo+1,mp(in,aux)));
							}
					}
				}
		}
		return maior;
}
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> matriz[i][j];
				if(matriz[i][j]=='1')
					ini.pb(mp(i,j));
			}
		}
		cout << bfs() << endl;
		ini.clear();
	}
}
3387 yasmin
