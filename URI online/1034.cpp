#include <bits/stdc++.h>
using namespace std;
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a,&b)
int n,m;

int A[30];
inline void scanint(int *x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
inline void printint(int n)
{
	if(n == 0)
	{
		putchar_unlocked('0');
		putchar_unlocked('\n');
	}
	else if(n == -1)
	{
		putchar_unlocked('-');
		putchar_unlocked('1');
		putchar_unlocked('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while(n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while(buf[i] != '\n')
			putchar_unlocked(buf[++i]);
	}
}

main(){

	int z,i,j,k,aux;
	scanint(&z);
	int dp[1000010];
	for(k=0;k<z;k++){
		scanint(&n);scanint(&m);
		
		for(i=0;i<n;i++){
			scanint(&A[i]);
		}
		for(i=1;i<=m;i++)
			dp[i] = 1010101;
		dp[0] = 0;
		for(i=1;i<=m;i++){
			for(j=0;j<n;j++){
				aux = i-A[j];
				if(A[j] <= i && dp[aux]+1 < dp[i])
					dp[i] = dp[aux]+1;
			}
		}
		printint(dp[m]);		
	}
	
}
