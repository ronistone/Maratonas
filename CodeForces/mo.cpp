#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define getchar_unlocked getchar
#define putchar_unlocked putchar

typedef long long int ll;
typedef pair<pair<ll,ll>, ll> iii;

iii Q[200010];
ll current,ans[200010];
ll A[200010],BLOCK=580,n,t; 

ll cont[1000100];
int a1,b1;

bool cmp(iii a, iii b){
	a1 = a.F.F/BLOCK;
	b1 = b.F.F/BLOCK;
	if(a1 != b1)
		return a1 < b1;
	return a.F.S < b.F.S;
}

void add(int x){
	current -= cont[x]*cont[x]*x;
	cont[x]++;
	current += cont[x]*cont[x]*x;
}
void remove(int x){
	current -= cont[x]*cont[x]*x;
	cont[x]--;
	current += cont[x]*cont[x]*x;
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
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int i;
	//scanf("%d %d",&n,&t);
	//cin >> n >> t;
	scanint(&n);scanint(&t);
	//BLOCK = sqrt(n);
	for(i=1;i<=n;i++)
		//scanf("%d",&A[i]);
		//cin >> A[i];
		scanint(&A[i]);
		
	for(i=0;i<t;i++){
		//scanf("%d%d",&Q[i].F.F,&Q[i].F.S);
		//cin >> Q[i].F.F >> Q[i].F.S;
		scanint(&Q[i].F.F);scanint(&Q[i].F.S);
		Q[i].S = i;
	}
	sort(Q,Q+t,cmp);
	
	
	int L=1,R=0,RR,LL;
	for(i=0;i<t;i++){
		LL = Q[i].F.F;
		RR = Q[i].F.S;
		while(R < RR){
			R++;
			add(A[R]);
		}
		while(R > RR){
			remove(A[R]);
			R--;
		}
		while(L < LL){
			remove(A[L]);
			L++;
		}
		while(L > LL){
			L--;
			add(A[L]);
		}
		ans[Q[i].S] = current;
	}
	for(i=0;i<t;i++)
		//cout << ans[i] << endl;
		printint(ans[i]);

}
