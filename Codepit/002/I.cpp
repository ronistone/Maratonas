#include <bits/stdc++.h>
using namespace std;

main(){
	
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i;
	double n,j,a,maior,aux,verifica;
	double meio,fim,inicio,auxcima,auxbaixo;
	double v[100010];

	while(cin >> n >> a and (a!=0 or n!=0)){
		
		maior = 0;
		for(i=0,verifica=0;i<n;i++){
			cin >> v[i];
			maior = max (maior, v[i]);
			verifica += v[i];
		}
		if(verifica==a){
			cout << ":D" << endl;
		}
		else if(verifica < a){
			cout << "-.-" << endl;
		}
		else{
			fim = maior;
			inicio = 0; 
			while(fim - inicio > 0.000001){ 					//busca binaria
				meio = (fim+inicio)/2;
				for(i=0,auxcima=0,auxbaixo=0; i < n;i++)	//faz a soma dos valores abaixo e a cima do corte
					if(v[i]>meio)
						auxcima+= v[i]-meio;
				if(auxcima==a or auxbaixo==a)
					break;
				else if(auxcima>a)
					inicio = meio;
				else
					fim = meio;
			}
			cout << fixed << setprecision(4) << meio << endl;
		}

	}
}