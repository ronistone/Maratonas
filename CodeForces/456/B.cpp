#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	
	ll n,k,i;
	
	cin >> n >> k;
	
	
	
	for(i=63;i>=0;i--){
		if((1LL << i)&n)
			break;
	}
	
	if(k == 1)
		cout << n << endl;
	else
		cout << (1LL << (i+1)) - 1LL << endl;
	
	
	
	
}
