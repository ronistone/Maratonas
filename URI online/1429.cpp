#include <bits/stdc++.h>
using namespace std;

int fat(int n)
{
	if (n) 
  	  return n*fat(n-1);
	else return 1;
}

main(){
	string entrada;
	int i,j,saida;
	char aux[2];

	while(cin >> entrada){
		if(entrada.size()>=0 and entrada[0] == '0')
			break;
		saida = 0;
		j = 0;
		aux[1] = '\0';
		int x;
		for(i=entrada.size()-1,x =0;i>=0;i--,x++){
			aux[0] = entrada[x];
			j = atoi(aux);
			j *= fat(i+1);
			saida +=j;
		}
		cout << saida << endl;
		entrada.clear();
	}
}