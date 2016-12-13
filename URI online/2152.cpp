#include <bits/stdc++.h>
using namespace std;

main(){
	int n,h,m,i;
	bool abriu;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> h >> m >> abriu;
		if(h>=0 && h<10)
			cout << "0" << h << ":";
		else
			cout << h << ":" ;
		if(m>=0 && m<10)
			cout << "0" << m;
		else
			cout << m;
		if(abriu)
			cout << " - A porta abriu!" << endl;
		else
			cout << " - A porta fechou!" << endl;
	}

}