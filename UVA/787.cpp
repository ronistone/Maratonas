#include <bits/stdc++.h>
using namespace std;
#define pb push_back

typedef long long int ll;
int n;
vector<ll> D;

inline bool scanint(ll *x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
	return true;
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
	ll aux;
	while(scanf("%lld",&aux)!=EOF){
		if(aux!=-999999)
			D.pb(aux);
		ll maior = aux;
		while(scanint(&aux) and aux!=-999999){
			if(aux!=-999999)
				D.pb(aux);
			if(aux > maior)
				maior = aux;
		}
		ll ans = -999999999;
		ll mul = 1;
		n = D.size();
		for (int i = 0; i < n; i++) {
			if(D[i]!=0){
				mul *= D[i];
				ans = max(ans, mul);
				//if(ans!=mul)
				//	mul = 1;
			}
			else{
				mul = 1;
			}
			//if (mul < 0) mul = 1;
			}
		if(maior > ans)
			ans = maior;
		printint(ans);
		D.clear();
	}
	
}
