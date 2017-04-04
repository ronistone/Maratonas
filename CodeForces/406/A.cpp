#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-1

typedef long long int ll;

main(){
	
	ll a,b,c,d,ans;
	ll aux;
	ll a1;
	while(cin >> a >> b >> c >> d){
		a1 = d-b;
		bool achou = false;
		for(int i=0;i<10000;i++){
			if(achou) break;
			for(int j=0;j<10000;j++){
				if(a1 == (i*a-j*c)){
					cout << (b+i*a) << endl;
					achou = true;
					break;
				}
			}
		}
		if(!achou) cout << -1 << endl;
	}


}
