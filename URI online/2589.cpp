#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<ll> primos;
bool prime[1000000002];

void sieve(){
	//memset(prime,true, sizeof(prime));
	primos.clear();
	prime[1] = true;
	ll i,j;
	for(i=2;i<=1000000001;i++){
		if(!prime[i]){
			primos.push_back(i);
			for(j=i*i;j<=1000000001;j+=i)
				prime[j] = true;
		}
	}
}


main(){
	sieve();
	cout << primos.size() << endl;
	//for(int i=0;i<primos.size();i++)
	//	cout << primos[i] << ", ";
	cout << endl;
}
