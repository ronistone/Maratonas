#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int d,i,f,x;
	
	cin >> d >> i >> x >> f;
	int ans = d%2==0? ((f+1)%2==0? i-x:i):((f+1)%2==0? i+x:i);
	cout << ans << endl;

}
