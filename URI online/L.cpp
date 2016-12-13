#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j;
	vector<double> v;
	double entrada,soma,aux;
	while(cin >> n and n){
		soma = 0;
		for(i=0;i<n;i++){
			cin >> entrada;
			v.push_back(entrada);
			soma +=entrada;
		}
		soma /= n;
		for(i=0, aux = 0;i<n;i++){
			if(v[i]>soma){
				aux += v[i]-soma;
			}
		}
		cout << aux << endl;
	}
}