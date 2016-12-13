#include <bits/stdc++.h>
using namespace std;

typedef struct{
		string nome;
		int peso,idade;
		double altura;
}Rena;

bool ordena(Rena i,Rena j){
	if(i.peso>j.peso)
		return true;
	else if(i.peso==j.peso){
			if(i.idade<j.idade)
				return true;
			else if(i.idade==j.idade){
				if(i.altura<j.altura)
					return true;
				else if(i.altura==j.altura){
					if(i.nome>j.nome)
						return true;
				}
			}
	}
	return false;
}


main(){
	int n,z,m;
	int i,j,k;
	vector<Rena> v;
	cin >> n;
	
	for(i=0;i<n;i++){
			cin >> z >> m;
			
			for(j=0;j<z;j++){
				Rena aux;
					cin.ignore();
					cin >> aux.nome >> aux.peso >> aux.idade >> aux.altura;
					v.push_back(aux);
			}
			sort(v.begin(),v.end(),ordena);
			//if(i!=0)
				//cout << endl;
			cout << "CENARIO {" << i+1 << "}" << endl;
			for(j=0;j<m;j++){
					cout << j+1 << " - "  << v[j].nome << endl;
			}
			v.clear();
			//cout << endl;
	}
}
