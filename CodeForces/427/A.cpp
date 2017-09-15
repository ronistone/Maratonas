#include <bits/stdc++.h>
using namespace std;

main(){
	int n,v1,v2,t1,t2,j1,j2;
	cin >> n >> v1 >> v2 >> t1 >> t2;
	
	j1 = (v1*n) + (2*t1);
	j2 = (v2*n) + (2*t2);
	if(j1 < j2)
		cout << "First" << endl;
	else if(j1 > j2)
		cout << "Second" << endl;
	else
		cout << "Friendship" << endl;
}
