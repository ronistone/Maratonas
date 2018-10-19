#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int A[3010],cost[3010];

#define INF 1000000000
int dp[3010][3010][4];
int n;


int solve(int p, int ant, int q){
	
	if(q==3) return dp[p][ant][q] = 0LL;
	if(p>n) return dp[p][ant][q] = INF;
	
	if(dp[p][ant][q]!=-1) return dp[p][ant][q];
	
	int ans = solve(p+1,ant,q);
	
	if(A[p]>A[ant])
		ans = min(ans, solve(p+1,p, q+1)+cost[p]);
			
	return dp[p][ant][q] = ans;
		
}
void print(int p, int ant, int q){
	if(q==3 or p>n) return;
	
	if(dp[p][ant][q] == dp[p+1][p][q+1]+cost[p]){
		cout << "Taken: " <<  p  << " --- " << cost[p] << endl;
		print(p+1,p,q+1);
	}
	else
		print(p,ant,q);
}

void clear(){
		
	for(int i=0;i<=n;i++){
		for(int l=0;l<=n;l++){
			for(int j=0;j<4;j++){
				dp[i][l][j] = -1;
			}
		}
	}
	
}

main(){
	
	cin >> n;
	A[0] = -INF;
	cost[0] = INF;
	
	for(int i=1;i<=n;i++){
		cin >> A[i];
	}
	for(int i=1;i<=n;i++){
		cin >> cost[i];
	}
	
	clear();
	int ans = solve(1,0,0);
	cout << (ans==INF?-1:ans) << endl;
//	print(1,0,0);

}
