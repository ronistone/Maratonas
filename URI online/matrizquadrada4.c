#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[101][101],i,n,j,x;


	while(scanf("%d", &n)!=EOF){
		x=n-1;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				m[i][j]=0;
				if(j>=n/3 && j<(n-n/3) && i>=n/3 && i<(n-n/3))
					m[i][j]++;
				else if(i==j)
					m[i][j]+=2;
				else if(j==x){
					m[i][x]=3;
				}
				if(n%2!=0 && i==((n-1)/2) && j==i)
					m[i][j]=4;
			}
			x--;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j==n-1){
					printf("%d\n",m[i][j]);
				}
			else
				printf("%d",m[i][j]);
			}
		}
		printf("\n");
	}
return 0;
}