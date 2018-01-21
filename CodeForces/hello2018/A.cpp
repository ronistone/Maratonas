#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long int ll;

main(){

	ll n,m;
	
	
	cin >> n >> m;
	
	if(n < 32){
		cout << m % (1 << n) << endl;
	}else{
		cout << m << endl;
	}

}
