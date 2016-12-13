#include <bits/stdc++.h>

using namespace std;

main(){
	int i,n,f1,f2,aux;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> f1 >> f2;
		if(f2>f1){
			aux = f1;
			f1 = f2;
			f2 = aux;
		}
		aux = f1%f2;
		if(aux == 0)
			aux = f2;
		else{
			while(true){
				f1 = f2%aux;
				if(f1==0){					
					break;
				}
				else{
					f2 = aux;
					aux = f1;
				}
			}
		}
		cout << aux << endl;
	}
}