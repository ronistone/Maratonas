#include <bits/stdc++.h>

using namespace std;

main(){
	int mes, dia,aux,falta,i;
	int diasmeses[] = {31,29,31,30,31,30,31,31,30,31,30,31};

	while(cin >> mes >> dia){
		if(mes == 12 && dia>25)
			cout << "Ja passou!" << endl;
		else if(mes == 12 && dia == 25)
			cout << "E natal!" << endl;
		else if(mes == 12 && dia == 24)
			cout << "E vespera de natal!" << endl;
		else{
			if(mes == 12)
				falta = 25-dia;
			else{
				falta = diasmeses[mes-1]-dia;
				for(i=10;i>=mes;i--){
					falta +=diasmeses[i];
				}
				falta +=25;
			}
			cout << "Faltam " << falta << " dias para o natal!" << endl;
		}
	}
}