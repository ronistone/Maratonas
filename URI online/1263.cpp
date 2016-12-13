#include <bits/stdc++.h>
using namespace std;

main(){
	int i,j,count;
	string entrada;
	bool letra;
	char aux,aux1;

	while(getline(cin,entrada)){
		setbuf(stdin,NULL);
		letra = false;
		count = 0;
		for(i=0;i<entrada.size();i++){
			if(!letra){
				if(i==0){
					aux = entrada[i];
					aux1 = ' ';
					letra = true;
				}
				else{
					if(toupper(aux) == toupper(entrada[i]) and toupper(aux1) != toupper(entrada[i])){
						count++;
						aux1 = entrada[i];
					}
					else{
						aux1 = aux;
						aux = entrada[i];
					}
					letra = true;
				}
			}
			else{
				if(entrada[i]==' ')
					letra = false;
			}
		}
		cout << count << endl;
	}
}