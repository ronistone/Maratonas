#include <bits/stdc++.h>
using namespace std;

main(){
	int ini,fim;
	cin >> ini >> fim;
	if(fim>=3 and fim<=96 and fim>ini)
		cout << "crescente" << endl;
	else if(fim>=3 and fim<=96 and fim<ini)
		cout << "minguante" << endl;
	else if(fim>=0 and fim<=2)
		cout << "nova" << endl;
	else if(fim>=97 and fim<=100)
		cout << "cheia" << endl;
}
