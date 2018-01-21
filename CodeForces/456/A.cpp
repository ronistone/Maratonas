#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ll y,b,w,x,z, ans;
	cin >> y >> b;
	
	cin >> x >> w >> z;
	
	y -= (2 * x) + (w);
	b -= w + (3*z);
	
	ans = (y<0?-y:0) + (b<0?-b:0);
	cout << ans << endl;
	
}
