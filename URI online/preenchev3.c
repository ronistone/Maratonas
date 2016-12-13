#include <stdio.h>
#include <stdlib.h>

int main(){
	double x,n[100];
	int i;

	scanf("%lf", &x);
	n[0]=x;
	printf("N[%d] = %.4lf\n", i, n[i]);
	for(i=1;i<100;i++){
		n[i] = n[i-1]/2;
		printf("N[%d] = %.4lf\n", i, n[i]);
	}
return 0;
}