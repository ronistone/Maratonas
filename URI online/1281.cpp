#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	char nome[51];
	float valor;
}produtos;

float busca(produtos *p,int n,char nome[],int quant){
	int i;
	for(i=0;i<n;i++){
		if(!strcmp(p[i].nome,nome))
			return p[i].valor*quant;
	}
	return 0;
}

main(){
	int n,i,j,q,c,quant;
	char nome[51];
	float valor;
	cin >> n;

	for(i=0;i<n;i++){
		cin >> q;
		valor = 0;
		produtos p[q];
		for(j=0;j<q;j++){
			cin >> p[j].nome >> p[j].valor;
		}
		cin >> c;
		for(j=0;j<c;j++){
			cin >> nome >> quant;
			valor += busca(p, q, nome,quant);
		}
		cout << fixed << setprecision(2) << "R$ " << valor << endl;
	}
}