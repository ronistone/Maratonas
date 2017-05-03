#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a,h;
vector<ll> A;


main(){

	ll n,x,y,z,i;

	cin >> z;

	for(ll j=0;j<z;j++){
		cin >> n >> h >> a;
		for(i=0;i<n;i++){
			cin >> x >> y;
			x = ceil((double)x/a)*y;
			A.push_back(x);
		}
		sort(A.rbegin(),A.rend());
		ll ans = 0;
		for(i=0;i<n;i++){
			h -= A[i];
			if(h <=0)
				break;
			ans++;
		}
		if(h > 0)
			cout << -1 << endl;
		else
			cout << ans << endl;
		A.clear();
	}	
}
