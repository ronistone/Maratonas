#include <stdio.h>
#include <stdlib.h>

int main(){
	int m[100][100],i,j,n,ini,fin,x;

	for(;;){
		scanf("%d", &n);
		if(n==0)
			break;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				m[i][j]=1;
			}
		}
		ini=1;
		fin=n-1	;
		for(x=0;x<n;x++){
			for(i=ini;i<fin;i++){
				for(j=ini;j<fin;j++){
					m[i][j]++;
				}
			}
					ini++;
					fin--;
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