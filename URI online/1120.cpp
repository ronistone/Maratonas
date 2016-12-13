#include <bits/stdc++.h>
using namespace std;

main(){
	int i,j,x;
	//string 
	char n,aux;
	//cin >> n >> m;
	char m[200],saida[200];
	scanf("%c %s", &n,m);
	while(true){
		if(n=='0' && strlen(m)==1 && m[0]=='0')
			break;
		getchar();
		bool zero = true;
		for(i=0,x = 0;i<strlen(m);++i){
			if(m[i]!=n){
				aux = m[i];
				saida[x] = aux;
				x++;
				if(aux!='0')
					zero = false;
			}
		}
		saida[x] = '\0';
		bool zeroesquerda = true;
		for(i=0,x=0;i<strlen(saida);i++){
			if(saida[i]!='0')
				zeroesquerda = false;
			if(!zeroesquerda){
				m[x] = saida[i];
				x++;
			}
		}
		m[x] = '\0';
		if(zero){	
			printf("0\n");
		}
		else
			printf("%s\n", m);

		setbuf(stdin,NULL);
		scanf("%c %s", &n,m);
	}
}