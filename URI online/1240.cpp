#include <bits/stdc++.h>

using namespace std;

bool verifica(long long a, long long b){
	int i=0,auxa,auxb,v =0;
	while(a!=0 && b!=0){
		auxa = a%10;
		auxb = b%10;
		if(auxb==auxa)
			v++;
		else
			return false;
		a /=10;
		b/=10;
		i++;
	}
	if(v==i)
		return true;
	else
		return false;
}

main(){
	int n, i;
	long long int a, b;
	bool x;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a >> b;
		if(a>=b){
			if(verifica(a,b))
				cout << "encaixa" << endl;
			else
				cout << "nao encaixa" << endl;
		}
		else
			cout << "nao encaixa" << endl;
	}
}