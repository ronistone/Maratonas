#include <stdio.h>
#include <stdlib.h>
int conta(long int m[][15],long int n){
	if(m[n-1][n-1]<10)
		return 1;
	else if(m[n-1][n-1]>=10 && m[n-1][n-1]<100)
		return 2;
	else if(m[n-1][n-1]>=100 && m[n-1][n-1]<1000)
		return 3;
	else if(m[n-1][n-1]>=1000 && m[n-1][n-1]<10000)
		return 4;
	else if(m[n-1][n-1]>=10000 && m[n-1][n-1]<100000)
		return 5;
	else if(m[n-1][n-1]>=100000 && m[n-1][n-1]<1000000)
		return 6;
	else if(m[n-1][n-1]>=1000000 && m[n-1][n-1]<10000000)
		return 7;
	else if(m[n-1][n-1]>=10000000 && m[n-1][n-1]<100000000)
		return 8;
	else if(m[n-1][n-1]>=100000000 && m[n-1][n-1]<1000000000)
		return 9;
	else if(m[n-1][n-1]>=1000000000 && m[n-1][n-1]<10000000000)
		return 10;
}

int main(){
	long int m[15][15],i,j,n,digi;

	for(;;){
		scanf("%ld", &n);
		if(n==0)
			break;
		m[0][0]=1;
		for(i=1;i<n;i++){
			m[i][0]= m[i-1][0] * 2;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j!=0)
				m[i][j] = m[i][j-1]*2;
				}
		}
			digi = conta(m,n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
					if(digi==1){
						if(j==n-1){
							printf("%1ld\n",m[i][j]);
						}
						else
							printf("%1ld ", m[i][j]);
					}
					else if(digi==2){
						if(j==n-1){
							printf("%2ld\n",m[i][j]);
						}
						else
							printf("%2ld ", m[i][j]);
					}
					else if(digi==3){
						if(j==n-1){
							printf("%3ld\n",m[i][j]);
						}
						else
							printf("%3ld ", m[i][j]);
					}
					else if(digi==4){
						if(j==n-1){
							printf("%4ld\n",m[i][j]);
						}
						else
							printf("%4ld ", m[i][j]);
					}
					else if(digi==5){
						if(j==n-1){
							printf("%5ld\n",m[i][j]);
						}
						else
							printf("%5ld ", m[i][j]);
					}
						else if(digi==6){
						if(j==n-1){
							printf("%6ld\n",m[i][j]);
						}
						else
							printf("%6ld ", m[i][j]);
					}
						else if(digi==7){
						if(j==n-1){
							printf("%7ld\n",m[i][j]);
						}
						else
							printf("%7ld ", m[i][j]);
					}
						else if(digi==8){
						if(j==n-1){
							printf("%8ld\n",m[i][j]);
						}
						else
							printf("%8ld ", m[i][j]);
					}
						else if(digi==9){
						if(j==n-1){
							printf("%9ld\n",m[i][j]);
						}
						else
							printf("%9ld ", m[i][j]);
					}
						else if(digi==10){
						if(j==n-1){
							printf("%10ld\n",m[i][j]);
						}
						else
							printf("%10ld ", m[i][j]);
					}
				}
		}
			printf("\n");
	}
return 0;
}