#include <bits/stdc++.h>
using namespace std;

main(){
	int i,j,saida;
	string entrada;
	double cont;
	map<char,double> m;
/*	m['W'] = 1;
	m['H'] = (1/2);
	m['Q'] = (1/4);
	m['E'] = (1/8);
	m['S'] = (1/16);
	m['T'] = (1/32);
	m['X'] = (1/64);*/
	m.insert(pair<char,double>('W',1));
	m.insert(pair<char,double>('H',(double)1/2));
	m.insert(pair<char,double>('Q',(double)1/4));
	m.insert(pair<char,double>('E',(double)1/8));
	m.insert(pair<char,double>('S',(double)1/16));
	m.insert(pair<char,double>('T',(double)1/32));
	m.insert(pair<char,double>('X',(double)1/64));
	
	while(getline(cin,entrada) and entrada!="*"){
		saida = 0;
		for(i=0,cont = 0;i<entrada.size();i++){
			if(entrada[i] != '/'){
				cont += m[entrada[i]];
			}
			else{
				if(cont==1)
					saida++;
				cont = 0;
			}
		}
		cout << saida << endl;
	}
}
