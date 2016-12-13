#include <bits/stdc++.h>
using namespace std;

main(){
	int valor,i,j,count=1;
	int v[] = {1,5,10,50};

	while(cin >> valor and valor!=0){
		int saida[] = {0,0,0,0};
		for(i=3;i>=0;i--){
			if(valor>=v[i]){
				while(true){
					valor-=v[i];
					saida[i]++;
					if(valor<v[i])
						break;
				}
			}
		}
		cout << "Teste " << count << endl;
		for(i=3;i>=0;i--){
			cout << saida[i];
			if(i!=0)
				cout << " ";
		}
		cout << endl << endl;
		count++;
	}
}