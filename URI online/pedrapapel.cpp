#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int i,n;
	char op1[10],op2[10];

	cin >> n;

	for(i=0;i<n;i++){
		cin >> op1;
		cin >> op2;

		if(strcmp(op1,"ataque")==0){
			if(strcmp(op2,"ataque")==0)
				cout << "Aniquilacao mutua" << endl;
			else
				cout << "Jogador 1 venceu" << endl;
		}
		else if(strcmp(op1,"pedra")==0){
			if(strcmp(op2,"papel")==0)
				cout << "Jogador 1 venceu" << endl;
			else if(strcmp(op2,"ataque")==0)
				cout << "Jogador 2 venceu" << endl;
			else
				cout << "Sem ganhador" << endl;
		}
		else if(strcmp(op1,"papel")==0){
			if(strcmp(op2,"papel")==0)
				cout << "Ambos venceram" << endl;
			else
				cout << "Jogador 2 venceu" << endl;
	
		}
	}


return 0;
}