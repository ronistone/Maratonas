#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n){
	ll saida = 4;
	for(int i=1;i<=n;i++){
		saida*= 2;
		saida -= (i*2)+2;
	}
	return saida;
}

main(){
	ll n;
	
	while(cin >> n and n>=0){
		cout << solve(n) << endl << endl;
	}
}
