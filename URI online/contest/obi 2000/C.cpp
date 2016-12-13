#include <bits/stdc++.h>
using namespace std;

main(){
	int n,aux,i,count = 0;
	while(cin >> n and n!=0){
		count++;
		for(i=1;i<=n;i++){
			cin >> aux;
			if(aux==i){
				cout << "Teste " << count << endl;
				cout << aux << endl << endl;
			}
		}
	}
}