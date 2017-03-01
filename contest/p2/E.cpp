#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


vector<ll> primos;



main(){
	string e;
	int n;
	gera();
	cin >> n;

	for(ll i=0;i<n;i++){
		cin >> e;	
		if(e.size() < 3)
			cout << "CHAR\n";
		else if(e.size() < 7)
			cout << "INT\n";
		else if(e.size() < 13)
			cout << "LONG LONG INT\n";
		else
			cout << "BIG INTEGER\n";
	}
	

}
