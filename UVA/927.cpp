#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ll n,j,d,k,i,c,z,x;
	
	cin  >> c;
	
	for(z=0;z<c;z++){
		cin >> i;
		ll coef[i+1];
		for(x=0;x<=i;x++){
			cin >> coef[x];
		}
		cin >> d >> k;
		ll atual = 0;
		j = 0;
		while(atual < k){
			j++;
			atual += j*d;
		}
		ll ans = coef[0];
		for(x=1;x<=i;x++){
			ans += coef[x]*pow(j,x);
		}
		cout << ans << endl;
	}
}
