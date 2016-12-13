#include <bits/stdc++.h>
using namespace std;

main(){
	string a,b;
	int n,i,j,x;

	cin >> n;
	for(i=0;i<n;i++){
		bool encaixa = true;
		cin >> a >> b;
		for(j=b.size(),x = a.size();j>=0;j--,x--){
			if(j>a.size() || b[j]!=a[x]){
				cout << "nao encaixa" << endl;
				encaixa = false;
				break;
			}
		}
		if(encaixa)
			cout << "encaixa" << endl;
	}
}