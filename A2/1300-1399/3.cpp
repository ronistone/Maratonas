#include <bits/stdc++.h>
using namespace std;

main(){
	string a,b;
	cin >> a;
	cin >> b;
	
	for(int i=0;i<a.size();i++){
		if(a[i]=='1' and b[i]=='1')
			cout << 0;
		else if(a[i] == '1' or b[i]=='1')
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;

}
