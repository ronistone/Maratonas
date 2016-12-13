#include <stdio.h>
#include <stdlib.h>

int main(){
		int n[1000],i,j=0,t;

		scanf("%d", &t);

		for(i=0;i<1000;i++){
			n[i] = j;
			j++;
			if(j==t)
				j=0;
			printf("N[%d] = %d\n", i, n[i]);
		}

return 0;
}