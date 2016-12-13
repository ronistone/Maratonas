#include <bits/stdc++.h>
using namespace std;

typedef struct{
	string cor,nome;
	char tam;
}camisetas;

bool ordena(camisetas a, camisetas b)
{
	if(a.cor == b.cor){
		if(a.tam == b.tam) return a.nome < b.nome;
		else return a.tam > b.tam;
	}else{
		return a.cor < b.cor;
	}
}

main(){
	int n,i,j,k;
	camisetas aux;
	vector<camisetas> v;
	bool entrou = false;
	while(cin >> n and n){
		if(entrou)
			cout << endl;
		cin.ignore();
		for(i=0;i<n;i++){
			getline(cin,aux.nome);
			cin >> aux.cor;
			cin >> aux.tam;
			v.push_back(aux);
			cin.ignore();
		}
		sort(v.begin(),v.end(),ordena);
		for(i=0;i<n;i++)
			cout << v[i].cor << " " << v[i].tam << " " << v[i].nome << endl;
		v.clear();
		entrou = true;
	}
}
