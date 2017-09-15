#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;
ll dp[100010];
ll A[100010];

ll solve(int current){
	if(current < 0) return 0;
	if(dp[current]!=-1) return dp[current];
	return dp[current] = max(solve(current-1),solve(current-2)+A[current]);
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int aux,maior=-1;
	cin >> n;
	//A[0] = -3;
	for(int i=0;i<n;i++){
		cin >> aux;
		A[aux]+=aux;
		maior = max(maior,aux);
	}
	memset(dp,-1,sizeof dp);
	cout << solve(maior) << endl;
}
