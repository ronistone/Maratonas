#include <stdio.h>

int main(){
	int x;
	scanf("%d", &x);
	int n[x],i,j,f=0;
	for(i=0;i<x;i++){
		scanf("%d", &n[i]);
	}

	for(i=0;i<x;i++){
		f=0;
		for(j=0;j<n[i];j++){
			if(j%2==0)
				f++;
			else
				f--;
		}
		printf("%d\n", f);
	}
return 0;
}