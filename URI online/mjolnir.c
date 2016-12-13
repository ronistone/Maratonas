#include <stdio.h>
#include <string.h>

int main(){
	int x;
	scanf("%d", &x);

	char nome[20], t[6]="Thor";
	int i,n;
	for(i=0;i<x;i++){
		scanf("%s %d", nome, &n);
		fflush(stdin);
	if(!strcmp(nome,t))
		printf("Y\n");
	else 
		printf("N\n");
	}

return 0;
}