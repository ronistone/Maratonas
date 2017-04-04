#include <bits/stdc++.h>
using namespace std;


typedef int ll;

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

	int i,a,aux,sum,at,w,n;
	
	
	while(scanf("%d",&n)!=EOF){
		
		scanint(&w);
		at = 0;
		sum = 0;
		for(i=0;i<n;i++){
			scanint(&aux);
			at += aux-w;
			if(at >= sum){
				sum = at;
			}
			if(at < 0)
				at = 0;
			
		}
		printint(sum);
	
	}
	
}
