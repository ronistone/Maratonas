#include <bits/stdc++.h>

using namespace std;

main(){
	double a,v,t,s;

	while(cin >> v >> t){
		if(t!=0){
			a = v/t;
			s = (v*t)+((1/2)*a*(t*t));
			cout << 2*s << endl;	
		}
		else
			cout << 0 << endl;
	
	}
}