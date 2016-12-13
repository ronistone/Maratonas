#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct
{
	double pessoas,consumo;

}casa;

int main(){
	int n,i,p,city=0,j,x;
	float cm;
	casa aux;

	while(cin>>n !=0){
		if(city<0)
			cout<< endl;
		city++;
		casa c[n];
		aux.consumo = 0;
		cm = 0;
		p = 0;
		for(i=0;i<n;i++){
			cin >> c[i].pessoas >> c[i].consumo;
			cm += c[i].consumo;
			c[i].consumo = floor(c[i].consumo/ c[i].pessoas);
			p += c[i].pessoas;
		}
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						if(c[i].consumo==c[j].consumo){
							c[i].pessoas += c[j].pessoas;
							c[j].pessoas = c[j].pessoas;
							c[j].consumo = c[j].consumo;
							n--;
						}
					}
				}
		cm /= p;
		for(x=0;x<n;x++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(c[i].consumo<c[j].consumo){
						aux.consumo = c[i].consumo;
						aux.pessoas = c[i].pessoas;
						c[i].consumo=c[j].consumo;
						c[i].pessoas=c[j].pessoas;
						c[j].consumo=aux.consumo;
						c[j].pessoas=aux.pessoas;

					}
					
				}
			}
		}
		cout << "Cidade# " << city << ":" << endl;
		for(i=0;i<n;i++){
			cout << c[i].pessoas <<"-" << c[i].consumo;
			if(i<n-1)
				cout << " ";
		} 
		printf("\nConsumo medio: %.2lf m3.\n", cm);

	}
	
return 0;
}