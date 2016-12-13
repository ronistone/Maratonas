#include <bits/stdc++.h>
using namespace std;

main(){
	string p;
	int l;
	double bs,iv,ev;
	double saida;

	int n,i,j;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> p >> l;

		cout << "Caso #" << i+1 << ": " << p << " nivel " << l << endl;

		cin >> bs >> iv >> ev;
		saida = (((iv+bs+(sqrt(ev)/8)+50) * l) / 50) + 10;
		cout << "HP: " << trunc(saida) << endl;

		cin >> bs >> iv >> ev;
		saida = (((iv+bs+(sqrt(ev)/8))*l)/50) + 5;
		cout << "AT: " << trunc(saida) << endl;

		cin >> bs >> iv >> ev;
		saida = (((iv+bs+(sqrt(ev)/8))*l)/50) + 5;
		cout << "DF: " << trunc(saida) << endl;

		cin >> bs >> iv >> ev;
		saida = (((iv+bs+(sqrt(ev)/8))*l)/50) + 5;
		cout << "SP: " << trunc(saida) << endl;
	}
}