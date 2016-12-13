#include <bits/stdc++.h>
using namespace std;

main(){
	string entrada;
	map<string,int> m;
	int i,j,n,z,aux,saida;
	
	cin >> n >> z;
	
	for(i=0;i<n;i++){
		cin >> entrada >> aux;
		m[entrada] = aux;
	}
	for(i=0,saida = 0;i<z;i++,saida=0){
		while(cin >> entrada and entrada!="."){
			saida+= m[entrada];
		}
		cout << saida << endl;
	}

}
