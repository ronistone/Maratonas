#include <iostream>

using namespace std;

int main(){
	int ini,f,d,dm,mi,mf;

	cin >> ini;
	cin >> mi;
	cin >> f;
	cin >> mf;

	if(ini == f && mi==mf){
		d = 24;
		dm = 0;	
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini == f && mi < mf){
		d = 0;
		dm = mf - mi;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini == f && mi > mf){
		d = 23;
		dm = 60 - mi;
		dm = dm + mf;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini > f && mi < mf){
		d = 24 - ini;
		d = d + f;
		dm = mf - mi;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini > f && mi > mf){
		d = 24 - ini-1;
		d = d + f;
		dm = 60 - mi;
		dm = dm + mf;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini > f && mi == mf){
		d = 24 - ini;
		d = d + f;
		dm = 0;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini < f && mi < mf){
		d = f - ini;
		dm = mf - mi;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini < f && mi > mf){
		d = f - ini - 1;
		dm = 60 - mi;
		dm = dm + mf;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}
	else if(ini < f && mi == mf){
		d = f - ini;
		dm = 0;
		//if(ini-f==1)
		//d=0;
		cout << "O JOGO DUROU " << d << " HORA(S) E " << dm << " MINUTO(S)\n";
	}


return 0;
}	