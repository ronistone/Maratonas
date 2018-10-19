#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000000
typedef long long int ll;

ll dist[18][18],t;
ll dp[18][8][(1<<19)];
int n,m,k;

void showDist(){
	
	
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
	
}


ll solve(int p, int k, ll mask){
	if(k<0) return MAX;
	//mask |= 1 << p;
	
	if(mask == (1 << (n+1))-1) return dp[p][k][mask] =  0LL;
	
	if(dp[p][k][mask]!=-1) return dp[p][k][mask];
	
	ll ans = MAX;
	for(int i=1;i<=n;i++){
		if(!(mask & (1<<i))){
			ans = min(ans,solve(i,k-1,(mask|(1<<i))));
			ans = min(ans, solve(i,k,(mask|(1<<i)))+dist[p][i]);
		}
	}
	return dp[p][k][mask] = ans;
}

void print(int p, int k, ll mask){
	cout << p << "  " << dp[p][k][mask] << endl;
	
	if(mask==(1<<(n+1))-1) return;
	
	for(int i=1;i<=n;i++){
		if(dp[p][k][mask] == dp[i][k-1][(mask|(1<<i))]){
			 print(i,k-1,(mask|(1<<i)));
			 return;
		}
		if(dp[p][k][mask] == dp[i][k][(mask|(1<<i))]+dist[p][i]){
			 print(i,k,(mask|(1<<i)));
			 return;
		}
	}
	
}

void clear(){
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dist[i][j] = MAX;
		}
		for(int j=0;j<6;j++){
			for(int w = 0;w<=(1<<(n+1));w++){
				dp[i][j][w] = -1;
			}
		}
	}

}


main(){
	int from,to;
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> n >> m >> k;
		
		clear();
		
		for(int j=0;j<m;j++){
			cin >> from >> to >> t;
			dist[from][to] = min(t, dist[from][to]);
			dist[to][from] = min(t, dist[to][from]);
		}
		
		for(int z=1;z<=n;z++){
			for(int j=1;j<=n;j++){
				for(int w=1;w<=n;w++){
					dist[z][j] = min(dist[z][j], dist[z][w]+dist[w][j]);
				}
			}
		}
		
		ll ans = solve(1,k, 3);
		
		if(ans != MAX)
			cout << ans << endl;
		else
			cout << -1 << endl;
		
	}

}
