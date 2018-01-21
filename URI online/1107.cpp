#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
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
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll S[100000];
	ll a,c,ans,aux,i,P;
	while(scanint(&a) and scanint(&c) and (a or c)){
		ans = 0;
		P = 0;
		for(i=0;i<c;i++){
			scanint(&aux);
			//cin >> aux;
			if(P==0 or S[P-1] > aux)
				S[P++] = aux;
			else{
				ans += aux - S[P-1];
				while(P>0 and S[P-1] <= aux) P--;
				S[P++] = aux;
			}
		}
		P>0? aux = S[P-1]: aux = a;
		
		while(P>0)	aux = min(aux,S[--P]);
		ans += a - aux;
		printint(ans);
		//cout << ans << endl;
	}

}
