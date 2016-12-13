#include <iostream>

using namespace std;

int main(){
	int ini,f,d;

	cin >> ini;
	cin >> f;

	if(ini == f){
		d = 24;
		cout << "O JOGO DUROU " << d << " HORA(S)\n";
	}
	else if(ini > f){
		d = 24 - ini;
		d = d + f;
		cout << "O JOGO DUROU " << d << " HORA(S)\n";
	}
	else if(ini < f){
		d = f - ini;
		cout << "O JOGO DUROU " << d << " HORA(S)\n";
	}


return 0;
}