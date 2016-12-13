#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[100][100],i,j,n,ini,fin,x,aux;

	while(scanf("%d", &n)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				m[i][j]=1;
			}
		}
		j=n-1;
		for(i=0;i<n;i++){
					m[i][j]++;
					j--;
			
		}
		for (i=0;i<n;i++){
            for (j=0;j<n;j++){
            	if(i!=j){
            		if(m[i][j]==1)
            			m[i][j]+=2;
            	}
               if (j==n-1){      
                  printf("%d", m[i][j]);
                  printf("\n");
               }
               else{
                  printf("%d", m[i][j]); 
               }
            }
         }
	}
return 0;
}