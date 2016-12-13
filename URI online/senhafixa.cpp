#include <iostream>

using namespace std;

int main(){
	int senha=2002,n;
	for(;;){
		cin >> n;
		if(n==senha){
			cout << "Acesso Permitido\n";
			break;
		}
		else
			cout << "Senha Invalida\n";
	}
return 0;
}