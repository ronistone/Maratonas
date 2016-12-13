#include <bits/stdc++.h>
using namespace std;

main(){
	int i,f;

	cin >> i >> f;

	if(i==f)
		cout << "O JOGO DUROU " << 24 << " HORA(S)" << endl;
	else if(i>f){
		f = 24 - i +f;
		cout << "O JOGO DUROU " << f << " HORA(S)" << endl;
	}
	else{
		f -= i;
		cout << "O JOGO DUROU " << f << " HORA(S)" << endl;
	}
}