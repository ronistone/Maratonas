#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ll n;
	map<ll,bool> div;
	cin >> n;
	
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i==0){
			div[i] = true;
			div[(n/i)] = true;
		}
	}
	
	ll num;
	for(ll i=33;i>0;i--){
		num = (((1LL<<i)-1) << (i-1));
		if(div[num]){
			cout << num << endl;
			break;
		}
	}
	
	
}
