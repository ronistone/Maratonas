#include <bits/stdc++.h>
using namespace std;

int n;
int M[19][19];
int A[19];
int dp[19][(1 << 19)];
int dead;
int solve(int current,int mask){

	if(mask == dead)
		return 0;
	
	if(dp[current][mask]!=-1) return dp[current][mask];
	
	int ans = 1e9+10;
	
	for(int i=0;i<n;i++){
		if(!(mask & A[i])){
			ans = min(ans,solve(current+1,(mask | A[i]))+M[i][current]);
		}
	}
	return dp[current][mask] = ans;
}


main(){
	for(int i=0;i<=18;i++)
		A[i] = 1 << i;
	while(scanf("%d",&n) and n){
		for(int i=0;i<n;i++)
			for(int j=0;j<(1 << (n+1));j++)
				dp[i][j] = -1;
		dead = (1 << n)-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&M[i][j]);
			}
		}
		
		//int ans = 1e9 + 10;
		
		cout << solve(0,0) << endl;
		
		//cout << ans << endl;
	
	}


}
