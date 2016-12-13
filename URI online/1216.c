#include <stdio.h>
#include <stdlib.h>

int main(){
	char lixo[100];
	float media=0;
	int i=0,dist;
	while(scanf("%[^\n]s",lixo)!=EOF){
		setbuf(stdin,NULL);
		scanf("%d",&dist);
		media +=dist;
		i++;
	}
	media /=i;
	printf("%f\n", media);
	return 0;
}