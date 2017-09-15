#include <bits/stdc++.h>
using namespace std;


main(){
	int n,m,x,y;
	
	cin >> n >> m >> x >> y;
	
	int aux = (m*x)+y;
	cout << (aux%2==0?"Direita":"Esquerda") << endl;

}
