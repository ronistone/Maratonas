#include <bits/stdc++.h>
using namespace std;

main(){
	int n,z,i,j,k,soma;
	string entrada;
	cin >> n;

	for(i=0;i<n;i++){
		cin >> z;
		soma = 0;
		for(j=0;j<z;j++){
			setbuf(stdin,NULL);
			cin >> entrada;
			setbuf(stdin,NULL);
			for(k=0;k<entrada.size();k++){
				soma += ((entrada[k]-65)+j+k);
			}
		}
		cout << soma << endl;
	}
}