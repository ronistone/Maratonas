#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
//typedef long long int ll;
typedef pair<int,int> ii;

int M[105];
ii dp[105][20001],w,n;

inline ii solve(int current,int sum){
	
	if(sum >= w) return mp(dp[current][sum] = sum,);
	if(current >= n) return mp(INT_MAX,INT_MAX);
	
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ii ans = min(solve(current+1,sum+M[current]),solve(current+1,sum));
	
	return mp(dp[current][sum] = ans, );
}
int cont;
inline int print(int current,int sum){
	
	if(sum>=w or current>=n) return 0;
	
	if(dp[current][sum] == dp[current+1][sum] and dp[current][sum]==dp[current+1][sum+M[current]]){
		return min(print(current+1,sum+M[current])+1,print(current+1,sum));
	}
	else if(dp[current][sum]==dp[current+1][sum+M[current]])
		return print(current+1,sum+M[current])+1;
	else
		return print(current+1,sum);
	
}



main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	
	cin >> t;
	
	for(int k=0;k<t;k++){	
		cin >> w;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> M[i];
		memset(dp,-1,sizeof dp);
		cout << solve(0,0,0).F << solve(0,0,0).S;
		//cout << " " << print(0,0) << endl;
	}
}
