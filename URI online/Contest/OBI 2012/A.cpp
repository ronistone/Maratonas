#include <bits/stdc++.h>
using namespace std;


main(){
	vector<double> d;
	double aux;
	int n;
	for(int i=0;i<5;i++){
		cin >> aux;
		d.push_back(aux); 
	}
	sort(d.begin(),d.end());
	double saida = 0;
	for(int i=1;i<4;i++){
		saida+=d[i];
	}
	cout << fixed << setprecision(1) << saida << endl;
}
