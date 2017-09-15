#include <bits/stdc++.h>
using namespace std;

typedef long long int  ll;

int dp[21][1 << 21];
int n;
int M[21];
int A[21][21];

inline int solve(int current,int w,int mask){
	
	if(mask == (1 << n)-1 or w>=420) return 0;
	
	if(dp[current][mask]!=-1) return dp[current][mask];
	
	int ans = 0;
	
	for(int i=0;i<n;i++){
		if(!(mask & (1 << i)) and w+A[current][i]+M[i] <= 420){
			ans = max(ans,solve(i,w+A[current][i]+M[i],mask | (1 << i))+1);
		}
	}
	return dp[current][mask] = ans;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n and n){
		for(int i=0;i<n;i++)
			cin >> M[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> A[i][j];
			}
		}
		int ans = 0;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			if(M[i] <= 420){
				ans = max(ans,solve(i,M[i],1 << i)+1);
			}
		}
		cout << ans << endl;
	}

}
