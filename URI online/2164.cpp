#include <bits/stdc++.h>
using namespace std;

main(){

	double n, saida;

	cin >> n;

	saida = (pow(((1 + sqrt(5))/2),n) - pow((1-sqrt(5))/2,n))/sqrt(5);

	cout << fixed << setprecision(1) << saida << endl;
}