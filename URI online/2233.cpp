#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
main(){
	ll r,g,b,ans;
	string e;
	stringstream ss;
	cin >> hex >> r;
	cin >> hex >> g;
	cin >> hex >> b;
	
	ans = (floor(g/b)*floor(g/b)) * (floor(r/g)*floor(r/g)) + 1 + (floor(r/g)*floor(r/g));
	
	ss << hex << ans;
	ss >> e;
	
	cout << e << endl;
}
