#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[11][100][2][2];
string a,b;
int k;
ll v;

void addRight(int i){
	v = (ll) v*10 + i;
}
void removeRight(int i){
	v = (ll) (v-i)/10;
}


/*
 *  solve(position, sum, matchUpperBound, matchLowerBound)
 * 	encontra todos os numeros entre [a,b] que são divisiveis por k e
 * 	a soma de seus digitos também sejam
 * 	
 */
ll solve(int p, int sum, bool match, bool matchLB){
	
	if(p==b.size()) return dp[p][sum][match][matchLB] = ((sum%k==0 and v%k==0)? 1LL:0LL);
	
	if(dp[p][sum][match][matchLB]!=-1) return dp[p][sum][match][matchLB];
	
	ll ans = 0;
	bool ma, maLB;
	for(int i=0;i<10;i++){
		ma = maLB = false;
		if((i < a[p]-'0' and matchLB) or (i > b[p]-'0' and match)) continue;
		if(i==a[p]-'0' and matchLB) maLB = true;
		if(i==b[p]-'0' and match) ma = true;
		
		addRight(i);
		ans += solve(p+1, sum+i, ma,maLB);
		removeRight(i);
	}	
	
	return dp[p][sum][match][matchLB] = ans;
}

void clear(){
		
	for(int i=0;i<11;i++){
		for(int j=0;j<100;j++){
			for(int w=0;w<2;w++){
				for(int x=0;x<2;x++){
					dp[i][j][w][x] = -1;
				}
			}
		}
	}
}

main(){

	int t,c=0;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b >> k;
		
		// Preenche de zeros a esquerda para o lower Bound ter a mesma quantidade de digitos
		a = string(b.size()-a.size(), '0') + a;
		
		clear();
		v = 0;
		
		cout << "Case " << ++c << ": " << solve(0, 0, true, true) << endl;
	}
	
}
