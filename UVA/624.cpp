#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int N,m,X;
int num[30];
ll dp[30][10000];

ll solve(int current,ll sum){
	if(sum > X) return 0LL;
	
	if(current==N || sum==X) return dp[current][sum] = sum;
			
	if(dp[current][sum]!=-1) return dp[current][sum];
	
	ll ans = max(solve(current+1,sum+num[current]),solve(current+1,sum));
	
	return dp[current][sum] = ans;
	
}
void path (ll i, ll j, ll ans) {

    if (i == N or j == ans)
      return;

    //cout << i << ' ' << j << '\n';
    //cout << dp[i][j] << ' ' << dp[i + 1][j + vet[i]] << '\n';

    if (dp[i+1][j + num[i]] == ans) {

      //cout << "pegou " << vet[i] << '\n';
      cout << num[i] << ' ';
      path (i + 1, j + num[i], ans);
    }

    else
      path (i + 1, j, ans);
}
main(){
	while(cin >> X >> N){
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<N;i++){
			cin >> num[i];
		}
		ll sum = solve(0,0);
		path(0,0,sum);
		cout << "sum:" << sum << endl;
	}
}
