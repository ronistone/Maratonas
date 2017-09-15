#include <bits/stdc++.h>
using namespace std;

typedef int ll;

ll dp[41][200][100];
int A[41][2];	
int n;
inline ll solve(int current,int v,int a){
	if(current == n) return 0;
	if(dp[current][v][a]!=-1) return dp[current][v][a];
	ll ans = solve(current+1,v,a);
	if(v+A[current][0] >= 0 and a+A[current][1] >=0)
		ans = max(solve(current+1,v+A[current][0],a+A[current][1])+1,ans);
	return dp[current][v][a] = ans;
}
inline void scanint(ll *x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
inline void printint(ll n)
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
	int v,a;
	while(scanf("%d",&n)!=EOF){
		scanint(&v);scanint(&a);
		for(int i=0;i<n;i++){
			cin >> A[i][0] >> A[i][1];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<200;j++)
				for(int l=0;l<100;l++)
					dp[i][j][l] = -1;
		}
		//memset(dp,-1,sizeof dp);
		printint(solve(0,v,a));
		//cout << solve(0,v,a) << endl;
	}
	
}
