#include <stdio.h>
#include <stdlib.h>

int main(){
	double m[12][12],soma=0;
	int l=0,c=11,ci=11,i,j;
	char t;

	scanf("%c", &t);

	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			scanf("%lf", &m[i][j]);
		}
	}
			for(i=1;i<11;i++){
				for(j=ci;j<12;j++){
					if(i<j){
						//printf("[%d][%d]\n", i,j);
						soma+= m[i][j];
						l++;
					}
				}
				c--;
				if(i<5)
					ci--;
				else if(i>6)
					ci++;
			}
	switch(t){
		case 'S':
			printf("%.1lf\n", soma);
		break;

		case 'M':
			printf("%.1lf\n", (soma/l));
	}
return 0;
}