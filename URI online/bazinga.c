#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int t,i,p,q;
	char shel[10],raj[10];

	scanf("%d", &t);

	for(i=0;i<t;i++){
		scanf("%s %s", shel, raj);
		if(!strcmp(shel,"pedra"))
			p=1;
		else if(!strcmp(shel,"papel"))
			p=2;
		else if(!strcmp(shel,"tesoura"))
			p=3;
		else if(!strcmp(shel,"lagarto"))
			p=4;
		else if(!strcmp(shel,"Spock"))
			p=5;
		if(!strcmp(raj,"pedra"))
			q=1;
		else if(!strcmp(raj,"papel"))
			q=2;
		else if(!strcmp(raj,"tesoura"))
			q=3;
		else if(!strcmp(raj,"lagarto"))
			q=4;
		else if(!strcmp(raj,"Spock"))
			q=5;
		if(p==q)
			printf("Caso #%d: De novo!\n", i+1);
		else if((p==3 && q==2) || (p==2 && q==1) || (p==1 && q==4) || (p==4 && q==5) || (p==5 && q==3) || (p==3 && q==4) || (p==4 && q==2) || (p==2 && q==5) || (p==5 && q==1) || (p==1 && q==3))
			printf("Caso #%d: Bazinga!\n", i+1);
		else
			printf("Caso #%d: Raj trapaceou!\n", i+1);
		
	}
return 0;
}