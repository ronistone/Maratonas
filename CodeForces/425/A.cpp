#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ll n,k;
	
	cin >> n >> k;
	
	if((n/k)%2 == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
