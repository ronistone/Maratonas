#include <stdio.h>
#include <stdlib.h>

int main(){
	int v[1000],l,i,n,np;

	while(scanf("%d",&l)!=EOF){
		n=0;
		np=0;
		for(i=0;i<l;i++){
			scanf("%d",  &v[i]);
			if(v[i]<10)
				np=1;
			else if(v[i]>=10 && v[i]<20)
				np=2;
			else if(v[i]>=20)
				np=3;
			if(np>n)
				n=np;
		}
		printf("%d\n", n);
	}
return 0;
}