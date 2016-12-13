#include <bits/stdc++.h>
using namespace std;

main(){
	int n,a,i,j;
	cin >> n;

	for(i=0;i<n;i++){
		cin >> a;
		int alunos[a];
		float soma = 0;
		for(j=0;j<a;j++){
			cin >> alunos[j];
			soma += alunos[j];
		}
		soma/=a;
		float acima = 0;
		for(j=0;j<a;j++){
			if(alunos[j]>soma)
				acima++;
		}
		acima/=a;
		acima*=100;
		cout << fixed << setprecision(3) << acima << "%" << endl;

	}
}