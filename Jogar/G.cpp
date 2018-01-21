#include <bits/stdc++.h>
using namespace std;

main(){
	
	int a[3],b[3];
	
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];
	sort(a,a+3);
	sort(b,b+3);
	
	if((a[0] <= b[2] and b[0] <= a[2]) or (b[0] <= a[2] and a[0] <= b[2]))
		cout << "E" << endl;
	else if(a[0] > b[2]){
		cout << "J1" << endl;
	}
	else
		cout << "J2" << endl;
	
}
