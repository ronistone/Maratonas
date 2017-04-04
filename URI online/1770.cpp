#include <bits/stdc++.h>
using namespace std;

typedef int ll;

ll m,k;
ll M[1010];
bool verifica[2000];

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
	ll aux,i;
	ll sum;
	ll ans;
	while(scanf("%d %d",&m,&k)!=EOF){
		sum = 0;
		ans = m;
		for(i=0;i<m;i++){
			scanint(&M[i]);
			verifica[i+1] = false;
		}
		for(i=0;i<k;i++){
			scanint(&aux);
			if(ans > 0){
				if(!verifica[aux]){
					verifica[aux] = true;
					ans--;
				}
				sum += M[aux-1];
			}
		}
		if(ans!=0)
			puts("-1");
		else
			printint(sum);
	}

}
