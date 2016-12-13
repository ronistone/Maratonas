#include <bits/stdc++.h>
using namespace std;

main(){
	string x,aux;
	int i,j,k,cont[]={0,0,0,0,0};
	int erro[] = {-1,-1,-1,-1,-1};

	cin >> x;

	cin >> k;
	for(i=0;i<5;i++){
		setbuf(stdin,NULL);
		cin >> aux;
		for(j=0;j<aux.size();j++){
			if(x[j]==aux[j]){
				cont[i]++;
			}
			else if(erro[i]==-1)
				erro[i] = j;
		}
	}
		int maior = -1;
		for(i=0;i<5;i++){
			if(cont[i]<maior)
				maior = i;
		}
		cout << maior << endl << erro[maior] << endl;

}