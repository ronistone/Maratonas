#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b,c,i,r;
	scanf("%d %d %d", &a,&b,&c);

	if(a==b){
		if(b<c)
			i=1;
		else
			i=0;
	}
	else if(a<b){
		if(b>c || b==c)
			i=0;
		else if(b<c){
			r = b-a;
			if(c-b<r)
				i=0;
			else
				i=1;
		}
	}
	else if(a>b){
		if(b<c || b==c)
			i=1;
		else if(b>c){
			r = a-b;
			if(b-c<r)
				i=1;
			else
				i=0;
		}
	}
	if(i==1)
		printf(":)\n");
	else if(i==0)
		printf(":(\n");

return 0;
}