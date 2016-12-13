#include <stdio.h>
#include <stdlib.h>

int main(){
	long int n,r1,r2,x,i;

	scanf("%ld", &n);

	for(i=0;i<n;i++){
		scanf("%ld %ld", &r1,&r2);

		x = ((r1 * 2) + (r2 * 2))/2;
		printf("%ld\n", x);
	}
return 0;
}