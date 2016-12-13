#include <bits/stdc++.h>
using namespace std;

main(){
	int n, saida = 0,aux;

	cin >> n;
	std::vector<int> v;
	bool achou = false;
	for(int i=0;i<n;i++){
		cin >> aux;
		v.push_back(aux);
		if(i!=0){
			if(v[i]<v[i-1] && !achou){	
				saida = i+1;
				achou = true;
			}
		}
	}
	cout << saida << endl;
}