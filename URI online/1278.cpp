#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,maior;
	string entrada;
	string aux;
	std::vector<string> v;

	cin >> n;

	while(n!=0){
		maior = 0;
		for(i=0;i<n;i++){
			setbuf(stdin,NULL);
			getline(cin,entrada);
			bool espaco = false;
			for(j=0;j<entrada.size();j++){
				if(entrada[j]!=' '){
					if(espaco and aux.size()!=0)
						aux.push_back(' ');
					aux.push_back(entrada[j]);
					espaco = false;
				}
				else
					espaco = true;
			}
			aux.push_back('\0');
			if(aux.size()>maior)
				maior = aux.size();
			v.push_back(aux);
			aux.clear();
		}

		for(i=0;i<n;i++){
			cout << setw(maior) << v[i] << endl;
		}
		v.clear();
		entrada.clear();
		cin >> n;
		//if(n!=0)
			cout << endl;
	}
}	