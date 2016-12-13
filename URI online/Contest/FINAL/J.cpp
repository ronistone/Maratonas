#include <bits/stdc++.h>
using namespace std;

main(){
	long long int n;
	bool nao = false;
	cin >> n;
	for(int i=2;i<sqrt(n);i++){
		if(n%i==0){
			nao = true;
			break;
		}
	}
	if(nao)
		cout << n-1 << endl;
	else
		cout << n << endl;
}
