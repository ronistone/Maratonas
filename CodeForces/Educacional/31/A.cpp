#include <bits/stdc++.h>
using namespace std;


main(){
	
	int n,t,a,ans;
	
	cin >> n >> t;
	ans = 0;
	for(int i=0;i<n;i++){
		cin >> a;
		a = 86400 - a;
		ans++;
		t -= a;
		if(t <= 0) break;
	}
	cout << ans << endl;

}
