#include <bits/stdc++.h>
using namespace std;

main(){
	int i,n;
	cin >> n;
	for(i=0;i<n;i++){
		string entrada;
		cin >> entrada;
		cout <<fixed << setprecision(2) << (float)entrada.size()/100 << endl;
	}
}