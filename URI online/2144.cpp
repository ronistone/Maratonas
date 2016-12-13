#include <bits/stdc++.h>
using namespace std;

main(){
	double w1,w2,r,media=0;
	int cont = 0;
	while(cin >> w1 >> w2 >> r and !(w1==0 and w2==0 and r==0)){
		w1 = w1*(1+(r/30));
		w2 = w2*(1+(r/30));
		w1 = (w1+w2)/2;

		if(w1>=1 and w1<13)
			cout << "Nao vai da nao" << endl;
		else if(w1>=13 and w1<14)
			cout <<"E 13" << endl;
		else if(w1>=14 and w1<40)
			cout << "Bora, hora do show! BIIR!" << endl;
		else if(w1>=40 and w1<=60)
			cout <<	 "Ta saindo da jaula o monstro!" << endl;
		else if(w1>60)
			cout << "AQUI E BODYBUILDER!!" << endl;
		media +=w1;
		cont++;
	}
	if((media/cont)>40)
		cout << endl <<  "Aqui nois constroi fibra rapaz! Nao e agua com musculo!" << endl;
}