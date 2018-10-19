#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

string e;
int k;
ll v;
ll dp[11][2][100];

void addLeft(int i){
	v = (ll) (v*10) + i;
}
void removeLeft(int i){
	v = v-i;	
	v = (ll) v/10;
}

ll solve(int p, bool match, int sum){
	if(p == e.size()){
		//if(((v%k==0 and sum%k==0)? 1LL:0LL) == 1LL) cout << "get: " << v << endl;
		return dp[p][match][sum]  = ((v%k==0 and sum%k==0)? 1LL:0LL);
	}
	
	//if(dp[p][match][sum]!=-1) return dp[p][match][sum];
	
	ll ans = 0;
	
	bool ma;
	for(int i=0;i<10;i++){
			ma = false;
			if(match and i>e[p]-'0') continue;
			else if(match and i==e[p]-'0') ma = true;
			
			addLeft(i);
			ans += solve(p+1, ma, sum+i);
			removeLeft(i);
	}
		
	return dp[p][match][sum] = ans;	
}

void clear(){
	for(int i=0;i<11;i++){
		for(int j=0;j<2;j++){
			for(int w=0;w<100;w++){
				dp[i][j][w] = -1;
			}
		}
	}
}

main(){
	string a, b;
	ll na,nb;
	int t;
	cin >> t;
	
	while(t--){
		cin >> na >> nb >> k;
		
		clear();
		na--;
		
		e = to_string(na);
		v = 0;
		ll zeroToA = solve(0,true,0);
		clear();
		v = 0;
		e = to_string(nb);
		ll ans = solve(0, true,0) - zeroToA;
		cout << ans << endl;
	}

}
