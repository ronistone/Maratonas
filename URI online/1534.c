 #include <stdio.h>
 #include <stdlib.h>

int main(void){
	int i,j,N,M[70][70];
	while(scanf("%d",&N) != EOF){
		if(N<3 || N>70)
			return 0;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(i==j){
					M[i][j]=1;
				}
				if(j==((N-1)-i)){
					M[i][j]=2;
				}
				else if(i!=j){
					M[i][j]=3;
				}
				printf("%d",M[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}