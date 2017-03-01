#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MAX_N 21*21*21
#define MAX_V -10e9
ll dp[21][21][21][MAX_N];
ll A[21][21][21];
int a,b,c;
ll num_min;
ll solve(ll x, ll y, ll z, ll n, ll sum){
	if(x<0 or x>=a or y<0 or y>=b or z<0 or z>=c) return MAX_V;
	
	if(dp[x][y][z][n]!=MAX_V) return dp[x][y][z][n];
	
	if(sum==MAX_V) sum = 0;
	
	ll ans = max(solve(x,y,z+1,0,MAX_V),solve(x,y,z+1,n+1,sum+A[x][y][z]));
	ans = max(ans,max(solve(x,y+1,z,0,MAX_V),solve(x,y+1,z,n+1,sum+A[x][y][z])));
	ans = max(ans,max(solve(x+1,y,z,0,MAX_V), solve(x+1,y,z,n+1,sum+A[x][y][z])));
	
	return dp[x][y][z][n] = max(sum,ans);
}
void reset(){
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			for(int k=0;k<c;k++){
				for(int l=0;l<a*b*c;l++){
					dp[i][j][k][l] = MAX_V;
				}
			}
		}
	}
}


main(){
	int n;
	
	cin >> n; 
	
	for(int k=0;k<n;k++){
		cin >> a >> b >> c;
		num_min = MAX_V;
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int l=0;l<c;l++){
					cin >> A[i][j][l];
					num_min = min(A[i][j][l],num_min);
				}
			}
		}
		reset();
		if(k!=0)
			cout << endl;
		cout << solve(0,0,0,0,0) << endl;
	}
	

}
