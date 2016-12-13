#include <bits/stdc++.h>
using namespace std;

main(){
	int a,b,c;
		cin >> a >> b >> c;
	
	if(a-b==0 or a-c==0 or b-c==0 or abs(a-b)-c==0 or abs(a-c)-b==0 
		or abs(b-c)-a==0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
}
