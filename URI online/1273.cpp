#include <bits/stdc++.h>
using namespace std;

main(){

	int n,i,maior;
	string entrada;
	std::vector<string> saida;

	cin >> n;

	while(n!=0){
		maior = 0;
		for(i=0;i<n;i++){
			cin >> entrada;
			if(entrada.size()>maior)
				maior = entrada.size();
			saida.push_back(entrada);
		}
		for(i=0;i<n;i++)
			cout << setw(maior) << saida[i] <<  endl;
		entrada.clear();
		saida.clear();
		cin >> n;
		if(n!=0)
			cout << endl;
	}
}