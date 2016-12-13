#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int x[n],i,menor = 10000000,posi;

	for(i=0;i<n;i++){
		scanf("%d", &x[i]);
		if(x[i]<menor){
			menor = x[i];
			posi = i;
		}
	}
	printf("Menor valor: %d\nPosicao: %d\n", menor,posi);

return 0;
}