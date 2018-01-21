#include <bits/stdc++.h>

using namespace std;


main(){

	vector<double> a;
	double aux,q;
	int n,ans = 0;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> aux;
		a.push_back(aux);
	}
	cin >> q;
	
	for(int i=0;i<n;i++){
		if(a[i] >= q)
			ans++;
	}
	cout << ans << endl;

}
