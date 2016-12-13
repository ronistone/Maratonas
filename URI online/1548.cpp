#include <bits/stdc++.h>
using namespace std;
int troca;

void ordena(vector<int>* v,vector<int>* posi){
	int i,j,tamv=v->size(),aux,auxposi;

	for(i=0;i<tamv;i++){
		for(j=0;j<tamv;j++){
			if((*v)[i]>(*v)[j]){
				aux = (*v)[i];
				auxposi = (*posi)[i];
				(*v)[i] = (*v)[j];
				(*posi)[i] = (*posi)[j];
				(*v)[j] = aux;
				(*posi)[j]= auxposi;
			}
		}
	}
}

main(){
	int n,m,i,j,entrada;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> m;
		std::vector<int> v,posi;
		troca = 0;
		for(j=0;j<m;j++){
			cin >> entrada;
			v.push_back(entrada);
			posi.push_back(j+1);
		}
		ordena(&v,&posi);
		for(j=0;j<m;j++){
			if(posi[j]==j+1)
				troca++;
		}
		cout << troca << endl;
	}

}