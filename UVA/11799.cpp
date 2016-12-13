#include <bits/stdc++.h>
using namespace std;

main(){
	int n,aux,m;
	int i,j;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> m;
		int maior = INT_MIN;
		for(j=0;j<m;j++){
			cin >> aux;
			if(aux> maior)
				maior = aux;
		}
		cout << "Case " << i+1 << ": " << maior << endl;
	}
}
