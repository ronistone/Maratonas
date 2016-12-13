#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[100][100],i,j,n,ini,fin,x,aux;

	for(;;){
		scanf("%d", &n);
		if(n==0)
			break;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				m[i][j]=1;
			}
		}
		aux=1;
		for(x=0;x<n-1;x++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i==j+aux){
						m[i][j]+=aux;
					}
					else if(j==i+aux){
						m[i][j]+=aux;
					}
				}
			}
			aux++;
		}
		for ( i = 0; i < n; i++ ){
            for ( j = 0; j < n; j++ ){
               if ( j == n-1 ){      
                  printf("%3d", m[i][j]);
                  printf("\n");
               }
               else{
                  printf("%3d ", m[i][j]); 
               }
            }
         }
         printf("\n");
	}
return 0;
}