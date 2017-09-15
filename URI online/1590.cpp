#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[45][20],m,k,n;
ll A[45];

ll solve(int current,int z){
	
	if(z==k) return (1LL<<32)-1;
	if(current>=m) return 0LL;
	
	//if(dp[current][z]!=-1) return dp[current][z];
	
	ll ans = max(solve(current+1,z),solve(current+1,z+1)&A[current]);
	
	return dp[current][z] = ans;
}


main(){
	
	cin >> n;
	
	
	for(int i=0;i<n;i++){
		
		cin >> m >> k;
		
		for(int j=0;j<m;j++){
			cin >> A[j];
		}
		//memset(dp,-1,sizeof dp);
		cout << solve(0,0) << endl;
	
	}


}
