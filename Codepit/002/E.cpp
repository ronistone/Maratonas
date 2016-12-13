#include <bits/stdc++.h>
using namespace std;

main(){
	double entrada;

	cin >> entrada;

	if(entrada>=0 and entrada<=25)
		cout << "Intervalo [0,25]" << endl;
	else if(entrada>25 and entrada<=50)
		cout << "Intervalo (25,50]" << endl;
	else if(entrada>50 and entrada<=75)
		cout << "Intervalo (50,75]" << endl;
	else if(entrada>75 and entrada<=100)
		cout << "Intervalo (75,100]" << endl;
	else
		cout << "Fora de intervalo" << endl;
}