#include <bits/stdc++.h>
using namespace std;


main(){
	vector<int> a(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a.begin(),a.end());
	
	cout << abs((a[1]+a[2])-(a[0]+a[3])) << endl;
}
