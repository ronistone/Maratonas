#include <stdio.h>
#include <stdlib.h>

int main(){
	float m[12][12],soma=0;
	int l,i,j;
	char t;

	scanf("%d %c", &l, &t);

	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			scanf("%f", &m[i][j]);
		}
	}
			for(i=0;i<12;i++)
				soma+= m[i][l];
	switch(t){
		case 'S':
			printf("%.1f\n", soma);
		break;

		case 'M':
			printf("%.1f\n", (soma/12));
	}
return 0;
}