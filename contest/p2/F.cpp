#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> primos;

void gera(){
	ll prim = 2;
	bool is = true;
	while(primos.size() < 104){
		for(ll i=2;i<=sqrt(prim);i++){
			if(prim%i==0){
				is = false;
				break;
			}
		}
		if(is){
			primos.push_back(prim);
		}
			prim++;
		is = true;
	}
}

main(){
	ll n;
	ll ant, at;
	gera();
	while(cin >> n and n){
		for(int i=0;i<n;i++){
			cout << n*primos[i];
			if(i!=n-1)
				cout << " ";
		}		
		cout << endl;
	}

}
