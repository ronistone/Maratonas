#include <bits/stdc++.h>
using namespace std;

int BIT[100100],A[100010];
int n,aux,x;

inline int query(int i){
	int ans = 0;
	for(;i>0;i-=(i&(-i)))
		ans+= BIT[i];
	return ans;
}
inline void update(int i,int value){
	for(;i<=n;i+=(i&(-i)))
		BIT[i] += value;
}

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
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	char e;
	//cin >> n;
	scanint(&n);
	for(int i=1;i<=n;i++){
		//cin >> A[i];
		scanint(&A[i]);
		update(i,A[i]);
	}
	while(scanf("%c%d",&e,&x)!=EOF){
		if(e=='?'){
			printint(query(x-1));
			//cout << query(x-1) << endl;
		}
		else if(e=='a'){
			update(x,-A[x]);
		}
	}
}
