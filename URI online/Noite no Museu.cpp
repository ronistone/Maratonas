#include <bits/stdc++.h>
using namespace std;

int n;
int A[21];
int M[21][21];

int dp[21][1<<21];

int solve(int current, int w,int visi){
	visi |= (1 << current);
	if(w<=0)
		return 0;
	int ans = 0;
	if(dp[current][visi]!=-1) return dp[current][visi];
	for(int i=0;i<n;i++){
		if(!(visi & (1 << i)) and w-(A[i]+M[current][i]) >= 0){
			ans = max(ans,solve(i,w-(A[i]+M[current][i]),visi)+1);
		}
	}
	return dp[current][visi] = ans;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n and n){
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			cin >> A[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> M[i][j];
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			int visi = (1 << i);
			if(420 - A[i] >=0)
				ans = max(ans,solve(i,420 - A[i],visi)+1);
		}
		
		cout << ans << endl;
	
	}

}
