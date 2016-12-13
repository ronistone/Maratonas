#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,im=0,pa=0,impar[5],par[5],j;

	for(i=0;i<15;i++){
		scanf("%d", &n);
		if(n%2==0){
			par[pa] = n;
			pa++;
			if(pa==5){
				for(j=0;j<5;j++){
					printf("par[%d] = %d\n", j,par[j]);
				}
				pa=0;
			}
		}
		else{
			impar[im] = n;
			im++;
			if(im==5){
				for(j=0;j<5;j++){
					printf("impar[%d] = %d\n", j,impar[j]);
				}
				im=0;
			}
		}
	}
		for(j=0;j<im;j++)
			printf("impar[%d] = %d\n", j,impar[j]);
		for(j=0;j<pa;j++)
			printf("par[%d] = %d\n", j,par[j]);
return 0;
}