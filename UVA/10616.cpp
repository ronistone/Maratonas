#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n,m,d;
int A[300];
ll ans;
ll dp[202][12][50];
map<int,int> Q,R;

inline ll solve(ll current,ll w,ll sum){
	
	if(current >= n or w == m) return (w==m and R[sum]==0)?(dp[current][w][sum] = 1LL):0LL;
	
	if(dp[current][w][sum]!=-1) return dp[current][w][sum];
	
	ll ans;
	if(w < m)
		ans = solve(current+1,w+1,Q[(R[sum]+A[current])%d]) + solve(current+1,w,sum);

	return dp[current][w][sum] = ans;
}
inline void print(ll current, ll w, ll sum){

	if(w==m and R[sum]==0) cout << "Acabou\n";
	if(current >= n or w == m) return;
	
	if(solve(current+1,w+1,Q[(R[sum]+A[current])%d])!=0){
		cout << "A[" << current << "] = " << A[current] << endl;
		print(current+1,w+1,Q[(R[sum]+A[current])%d]);
	}
	print(current+1,w,sum);
	
}


main(){
	int q,cont=0;
	int x = 0,z=21;
	for(int i=0;i<21;i++,x++,z++){
		Q[i] = x;
		Q[-i] = z;
		R[x] = i;
		R[z] = -i;
	}
	
	while(scanf("%d %d",&n,&q)!=EOF and n and q){	
		for(int i=0;i<n;i++)				
			scanf("%d",&A[i]);
		
		printf("SET %d:\n",++cont);
		for(int i=0;i<q;i++){
			memset(dp,-1,sizeof dp);
			scanf("%d %d",&d,&m);
			printf("QUERY %d: %lld\n",i+1,solve(0,0,0));
			print(0,0,0);
		}
	}
}
