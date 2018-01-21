#include <bits/stdc++.h>
using namespace std;

main(){
	
	int n,e,f,c,ans;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> e >> f >> c;
		ans = (e+f)/c;
		e = (e+f)%c;
		ans += (ans+e)/c;
		ans += (((ans+e)/c) + ((ans+e)%c))/c;
		cout << ans << endl;
	}

}
