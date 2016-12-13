#include <bits/stdc++.h>
using namespace std;

main(){
	int n,j1,j2;
	string n1,n2;
	int contador = 1;
	while(cin >> n and n){
		cin.ignore();
		cin >> n1;
		cin.ignore();
		cin >> n2;
		cout << "Teste " << contador << endl;
		for(int i=0;i<n;i++){
				cin >> j1 >> j2;
				cout << ((j1+j2)%2==0 ? n1 : n2) << endl;
		}
		cout << endl;
		contador++;
	}

}
