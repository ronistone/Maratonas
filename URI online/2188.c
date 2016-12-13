#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b,c,d,i,n;
	int count = 1;
	while(scanf("%d", &n) && n!=0){
		int x1 = -1000000000, y1 = 1000000000, 
	        x2 = 1000000000, y2 = -1000000000;
		for(i=0;i<n;i++){
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if (a > x1)
				x1 = a;
        	if (b < y1)
        		y1 = b;
        	if (c < x2)
        		x2 = c;
        	if (d > y2)
        		y2 = d;
		}
		printf("Teste %d\n", count);
		if (x2 < x1 || y1 < y2)
			printf("nenhum\n");
		else{
			printf("%d %d %d %d\n", x1,y1,x2,y2);
		}
		count ++;
		puts("");
	}
return 0;

}