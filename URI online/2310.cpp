#include <bits/stdc++.h>
using namespace std;


main(){
	string nome;
	int i,n;
	double st,s,bt,b,at,a,saida,sa,ba,aa;
	
	cin >> n;

	for(i=0;i<n;i++){
		cin >> nome;
		cin >> sa >> ba >> aa;
		s+= sa;
		b+= ba;
		a+= aa;
		cin >> sa >> ba >> aa;
		st+= sa;
		bt+= ba;
		at+= aa;

	}
		cout << "Pontos de Saque: " << fixed << setprecision(2)
			<< (st/s)*100 << " %." << endl;
		cout << "Pontos de Bloqueio: " << fixed << setprecision(2)
			<< (bt/b)*100 << " %." << endl;
		cout << "Pontos de Ataque: " << fixed << setprecision(2)
			<< (at/a)*100 << " %." << endl;


}
