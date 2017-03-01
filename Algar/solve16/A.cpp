#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	
	ll a,b,c;
	
	while(cin >> a >> b >> c and !(!a and !b and !c)){
		if((c-1)%5==0){
			if((c-1)/5>=a and (c-1)/5<=b){
				cout << "Achou." << endl;
				continue;
			}
		}
		
		cout << "Nao achou." << endl;
	}
	
}
