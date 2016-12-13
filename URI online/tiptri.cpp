#include <iostream>

using namespace std;

int main(){
	float n[3],aux;
	int i,j;

	for(i=0;i<3;i++)
		cin >> n[i];

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(n[i] > n[j]){
				aux = n[i];
				n[i] = n[j];
				n[j] = aux;
			}
		}
	}

	if(n[0] >= n[1] + n[2]){
		cout << "NAO FORMA TRIANGULO\n";
	}
	else{
		if((n[0] * n[0]) == (n[1]*n[1]) + (n[2]*n[2]))
			cout << "TRIANGULO RETANGULO\n";
		if((n[0] * n[0]) > (n[1]*n[1]) + (n[2]*n[2]))
			cout << "TRIANGULO OBTUSANGULO\n";
		if((n[0] * n[0]) < (n[1]*n[1]) + (n[2]*n[2]))
			cout << "TRIANGULO ACUTANGULO\n";
		if(n[0] == n[1] && n[0] == n[2])
			cout << "TRIANGULO EQUILATERO\n";
		if((n[0]==n[1] && n[0]!=n[2]) || (n[0]==n[2] && n[0]!=n[1]) || (n[1]==n[2] && n[1]!=n[0]))
			cout << "TRIANGULO ISOSCELES\n";
	}

	return 0;

}