#include <bits/stdc++.h>
using namespace std;


main(){
	char entrada[80];
	int processos,i,j,z,saida;

	while(cin >> entrada){
		cin >> processos;
		saida = 0;
		for(i=0,z = 0;i<strlen(entrada);i++){
			if(entrada[i]=='W'){
				if(z){
					saida++;
					z = 0;
				}
				saida++;
			}
			else if(entrada[i]=='R'){
				z++;
			}
			if(z==processos){
				z = 0;
				saida++;
			}
		}
		if(z)
			saida++;
		cout << saida << endl;
	}

}