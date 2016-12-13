#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int a,b,c,i,x;

	for(;;){
		scanf("%d", &a);
		if(a==0)
			break;
		scanf("%d %d", &b,&c);
		x = (a*b*100)/c;
		x = sqrt(x);
		printf("%d\n", x);

	}
return 0;
}