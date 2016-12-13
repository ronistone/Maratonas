#include <bits/stdc++.h>

using namespace std;

main(){
	long long int ini,a;

	while(cin >> ini >> a){
		ini = ini-a;
		if(ini<0)
			ini*=-1;
		cout << ini << endl;
	}
}