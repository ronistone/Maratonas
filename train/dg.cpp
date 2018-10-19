#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

main(){
	
	int t;
	double a,b,mod;
	ll ans;
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> a >> b >> mod;
		
		ans = (floor(b/mod) - ceil(a/mod));
		
		cout << ans << endl;
		
	}
	
}	
