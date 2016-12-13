#include <bits/stdc++.h>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i,n,p,u;

	cin >> n;

	for(i=0;i<n;i++){
		cin	>> p >> u;
		cout << (p*u)/2 << " cm2" << endl;
	}
}