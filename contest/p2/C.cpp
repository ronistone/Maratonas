#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	string E;
	ll n;
	
	while(cin >> E){
		ll sum = 0;
		for(ll i=0;i<E.size();i++){
			sum += E[i] - '0';
		}
		if(sum%3==0)
			cout << "PAR\n";
		else
			cout << "IMPAR\n";
		
	}

}
