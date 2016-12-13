#include <stdio.h>

int main(){
	char saida[]="LIFE IS NOT A PROBLEM TO BE SOLVED";
	int x,i;
	scanf("%d", &x);

	for(i=0;i<x;i++){
		putchar(saida[i]);
	}
	printf("\n");
return 0;
}