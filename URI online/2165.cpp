#include <bits/stdc++.h>
using namespace std;

main(){

	string entrada;

	getline(cin,entrada);

	if(entrada.size()<=140)
		cout  << "TWEET" << endl;
	else
		cout << "MUTE" << endl;
}