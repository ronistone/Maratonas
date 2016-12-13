#include <bits/stdc++.h>
using namespace std;

main(){
	double n,final,aux,maior,menor;

	cin >> n;

	menor = n/log(n);
	maior = menor* 1.25506;

	cout << fixed << setprecision(1) << menor << " " << maior << endl;
}