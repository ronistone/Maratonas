#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int aux,n,m,sizeA,sizeB,x,y,i;
	int a[10010];
	int ca[100010],cb[100010];


	while(scanf("%d %d",&n, &m) && (n && m)){
		memset(ca,0,sizeof(ca));
		memset(cb,0,sizeof(cb));
		x = 0; y = 0;
		sizeA = 0; sizeB = 0;
		for(i=0;i<n;i++){
			scanf("%d",&aux);
			if(!ca[aux]){
				a[sizeA] = aux;
				sizeA++;
				ca[aux] = 1;
			}
		}
		for(i=0;i<m;i++){
			scanf("%d",&aux);
			if(!cb[aux]){
				sizeB++;
				cb[aux] = 1;
				if(!ca[aux]){
					y++;
				}
			}
		}
		for(i=0;i<sizeA;i++){
			if(!cb[a[i]])
				x++;
		}
		if(x < y)
			printf("%d\n",x);
		else
			printf("%d\n",y);
	}
	return 0;
}
