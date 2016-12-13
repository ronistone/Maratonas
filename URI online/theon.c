#include <stdio.h>
#include <stdlib.h>

int main(){
	int x;
	
	scanf("%d", &x);
	int v[x],i,aux=100,f;
	for(i=0;i<x;i++){
		scanf("%d", &v[i]);
		if(v[i]<aux){
			aux = v[i];
			f = i;
		}
	}
	printf("%d\n", f+1);
return 0;
}