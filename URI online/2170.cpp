#include <bits/stdc++.h>
using namespace std;

main(){
	double x,y,count=1,saida;

	while(cin >> x >> y){
		cout << "Projeto " << (int)(count) << ":" << endl;
		cout << "Percentual dos juros da aplicacao: ";
		cout << fixed << setprecision(2) <<  ((y/x)-1)*100 << " %" << endl << endl;
		count++;
	}
}