#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll b,g;

ll dp[1020][1020];

ll fat(ll n){
	ll ans = 1;
	while(n>0){
		ans *= n;
		n--;
	}
	return ans;
}
ll comb(ll boy,ll girl){
	ll fb = fat(boy);
	ll fg = fat(girl);
	ll fbg = fat(boy-girl);
	return fb/(fbg);
}

inline ll solve(ll boy, ll girl){
	if(girl >= boy) return 0LL;
	if(girl<=1) return 1LL;
	if(dp[boy][girl]!=-1) return dp[boy][girl];
	
	ll ans = solve(boy-1,girl) + solve(boy,girl-1) + solve(boy-1,girl-1) + boy*girl;
	ans = ans%1000000007;
	
	return dp[boy][girl] = ans;	
}


main(){
	
	memset(dp,-1,sizeof dp);
	while(cin >> b >> g and b and g){
		cout << solve(b,g) << endl;
		//cout << comb(b,g) << endl;
	}

}
