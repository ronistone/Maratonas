#include <bits/stdc++.h>
using namespace std;


main(){
	double e;
	long double x,l,i;
	while(cin >> l){
		if(l==0)
			break;
		i = l+(l-3);
		x = (i-l)/l;
		cout << fixed << setprecision(6) << x << endl;
	}

}
