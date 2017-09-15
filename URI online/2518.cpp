#include <bits/stdc++.h>
using namespace std;

main(){
	double h,c,l,n,ans;
	while(cin >> n){
		cin >> h >> c >> l;
		
		ans = (sqrt(h*h+c*c)*n*l)/10000;
		cout << fixed  << setprecision(4) << ans << endl;
	}

}
