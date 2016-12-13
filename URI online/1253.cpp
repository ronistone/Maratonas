#include <bits/stdc++.h>

using namespace std;

main(){
	int n,casas,aux;
	string palavra;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> palavra;
		cin >> casas;
		for(int j=0;j<palavra.size();j++){
			palavra[j] -=casas;
			if(palavra[j]<65){
				aux = 65 - palavra[j];
				palavra[j] = 91 - aux;
			}
		}
		cout << palavra << endl;
	}
}