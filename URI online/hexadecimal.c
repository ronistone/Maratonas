#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int x;
	char num[200];

	scanf("%d", &x);
	itoa(x,num,16);
	printf("%x\n", toupper(x));
return 0;
}