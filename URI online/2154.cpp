#include <bits/stdc++.h>
using namespace std.

main(){
	int n,i,q;
	string poli;
	char aux[5];
	char lixo;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> q;
		for(j=0;j<q;j++){
			cin >> poli;
			cin >> lixo;
			for(int x=0;x<strlen(aux);x++){
				if(poli=='x')
					break;
				aux = poli[x];
			}
		}
	}
}