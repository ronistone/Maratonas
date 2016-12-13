#include <bits/stdc++.h>
using namespace std;

main(){
	string numero, cutoff, entrada;
	int i,j,k;
	double saida;

	while(cin >> entrada){
		if(entrada[0] == '.'){
			numero = '0';
			numero +=entrada;
		}
		else
			numero = entrada;
		entrada.clear();
		cin >> entrada;
		if(entrada[0] == '.'){
			cutoff = "0";
			cutoff += entrada;
		}
		else
			cutoff = entrada;
		entrada.clear();
		size_t a = numero.find('.'),b = cutoff.find('.');
		if(stod(numero,&a)>=stod(cutoff,&b)){
			saida = ceil(stod(numero));
		}
		else
			saida = floor(stod(numero));

		cout << "flutuante: " << stod(numero,&a) <<endl <<  "cutoff: " << stod(cutoff,&b) << endl;
		cout << fixed << setprecision(0) << saida << endl;
	}

}