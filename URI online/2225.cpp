#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > Grafo(16);
int M[17][17];
int dp[17][1<<17][7];
int n,m,k,from,to,c;


int solve(int current,int mask,int tele){
	if(mask==(1<<n)-1) return 0;
	
	if(dp[current][mask][tele]!=-1) return dp[current][mask][tele];
	int ans = 10000000;
	for(int i=0;i<Grafo[current].size();i++){
		if(!((1<<Grafo[current][i].first) & mask))
			ans = min(ans,solve(Grafo[current][i].first, mask | (1<<Grafo[current][i].first), tele)+Grafo[current][i].second);
	}
	if(tele < k)
		for(int i=0;i<n;i++)
			if(!((1<<i)&mask))
				ans = min(ans,solve(i,mask|(1<<i),tele+1));
	return dp[current][mask][tele] = ans;
}


main(){
	int z;
	cin >> z;
	
	for(int x=0;x<z;x++){
		cin >> n >> m >> k;
		for(int i=0;i<=n;i++)
			Grafo[i].clear();
		for(int i=0;i<=16;i++)
			for(int j=0;j<16;j++)
				M[i][j] = 10000000;
				
		for(int i=0;i<m;i++){
			cin >> from >> to >> c;
			M[from][to] = min(M[from][to],c);
			//Grafo[from-1].push_back(make_pair(to-1,c));
			//Grafo[to-1].push_back(make_pair(from-1,c));
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					M[i][j] = min(M[i][j],M[i][k]+M[k][j]);
				}
			}
		}
		memset(dp,-1,sizeof dp);
		int ans = solve(0,1,0);
		cout << (ans==10000000? -1:ans) << endl;
	}
}
