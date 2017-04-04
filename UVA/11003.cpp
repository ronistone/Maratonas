#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef struct no{
	
	ll w,l;
	no(ll w_,ll l_): w(w_),l(l_){}
	no(){}
	
}caixa;
caixa C[1010];
int n;

ll dp[1010][6011],ans;

ll solve(ll current,ll w){
	if(current >= n or w <= 0) return (w<0)? LLONG_MIN:0LL;
	
	if(dp[current][w]!=-1) return dp[current][w];
	
	
	ans = max(solve( current+1,min((w - C[current].w),C[current].l) )+1, solve(current+1,w));
	
	return dp[current][w] = ans;
}
void print(ll current,ll w){
	if(current >= n or w <= 0) return;
	
	if(solve(current+1,min((w-C[current].w),C[current].l))+1 == dp[current][w]){
			printf("C[%lld]\t-\t%lld\t= %lld\n",current, C[current].w, min((w-C[current].w),C[current].l));
			print(current+1,min((w-C[current].w),C[current].l));
	}
	else{
		print(current+1,w);
	}
	
}

main(){
	while(scanf("%d",&n)!=EOF and n){
		for(int i=0;i<n;i++)
			scanf("%lld %lld",&C[i].w,&C[i].l);
		memset(dp,-1,sizeof dp);
		printf("%lld\n",solve(0,6010));
		print(0,6010);
	}
}
