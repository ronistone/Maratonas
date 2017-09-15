#include <bits/stdc++.h>
using namespace std;

main(){
	int A[4];
	
	cin >> A[0] >> A[1] >> A[2];
	
	sort(A,A+3);
	if(A[2]>=A[0]+A[1]){
		cout << "Invalido" << endl;
	}
	else{
		if(A[0]==A[1] and A[0]==A[2])
			cout << "Valido-Equilatero" << endl;
		else if(A[0]==A[1] or A[0]==A[2] or A[1]==A[2])
			cout << "Valido-Isoceles" << endl;
		else
			cout << "Valido-Escaleno" << endl;
		
		if(A[2]*A[2] == A[0]*A[0]+A[1]*A[1])
			cout << "Retangulo: S" << endl;
		else
			cout << "Retangulo: N" << endl;
	}
}
