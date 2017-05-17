#include <bits/stdc++.h>
using namespace std;


main(){

	string e;
	int aux,n;
	while(getline(cin,e)){
		
		cin >> n;
		
		for(int i=0;i<n;i++){
			cin >> aux;
			cout << e[aux-1];
		}
		cout << endl;
		cin.ignore();
	}


}
