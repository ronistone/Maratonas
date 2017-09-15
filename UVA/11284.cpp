#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long int ll;

ll Grafo[55][55];
pair<ll,ll> M[14];
ll dp[14][1<<14];
int n;
inline ll solve(int current,int mask){
	if(mask == (1 << n)-1) return -Grafo[M[current].F][0];
	if(dp[current][mask]!=-100000000) return dp[current][mask];
	
	ll ans = -Grafo[M[current].F][0];
	for(int i=1;i<n;i++){
		if(!(mask & (1 << i))){
			ans = max(ans,solve(i,mask | 1 << i) + M[i].S - Grafo[M[current].F][M[i].F]);
		}
	}
	return dp[current][mask] = ans;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int z,from,to,q,l;
	double aux;
	ll w;
	cin >> z;
	
	for(int k=0;k<z;k++){
		cin >> q >> l;
		for(int i=0;i<=q;i++){
			for(int j=0;j<=q;j++){
				Grafo[i][j] = i==j? 0:1000000000;
			}
		}
		ll sum = 0;
		for(int i=0;i<l;i++){
			cin >> from >> to >> aux; w = aux*10000;
			Grafo[from][to] = Grafo[from][to] < 0? w:min(w,Grafo[from][to]);
			Grafo[to][from] = Grafo[to][from] < 0? w:min(w,Grafo[to][from]);
		}
		cin >> n;n++;
		M[0].F = 0;
		M[0].S = 0;

		for(int i=1;i<n;i++){
			cin >> M[i].F >> aux;
			M[i].S = aux*10000;
			sum += M[i].S;
		}
		for(int b=0;b<=q;b++){
			for(int i=0;i<=q;i++){
				for(int j=0;j<=q;j++){
					Grafo[i][j] = min(Grafo[i][j],Grafo[i][b]+Grafo[b][j]);
					Grafo[j][i] = Grafo[i][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++){
				dp[i][j] = -100000000;
			}
		}
		ll ans = solve(0,1);
		if(ans <= 0)
			cout << "Don't leave the house" << endl;
		else
			cout << fixed << setprecision(2) << "Daniel can save $" << ans/10000.0 << endl;
	}

}
