#include <bits/stdc++.h>
using namespace std;
#define pb push_back

typedef long long int ll;
int n;
vector<ll> D;


main(){
	ll aux;
	while(cin >> aux){
		if(aux!=-999999)
			D.pb(aux);
		ll maior = aux;
		while(cin >> aux and aux!=-999999){
			if(aux!=-999999)
				D.pb(aux);
			if(aux > maior)
				maior = aux;
		}
		ll ans = -999999999;
		ll mul = 1;
		n = D.size();
		for (int i = 0; i < n; i++) {
			if(D[i]!=0){
				mul *= D[i];
				ans = max(ans, mul);
				//if(ans!=mul)
				//	mul = 1;
			}
			else{
				mul = 1;
			}
			//if (mul < 0) mul = 1;
			}
		if(maior > ans)
			ans = maior;
		cout << ans << endl;
		D.clear();
	}
	
}
