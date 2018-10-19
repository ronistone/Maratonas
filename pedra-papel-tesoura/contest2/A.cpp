#include <bits/stdc++.h>
using namespace std;

main(){
	
	int a, ant;
	bool fail = false;
	ant = -1000000;
	
	for(int i=0;i<5;i++){
		cin >> a;
		if(a < ant)
			fail = true;
		ant = a;
	}
	
	if(fail)
		cout << "NAO" << endl;
	else
		cout << "SIM" << endl;
}
