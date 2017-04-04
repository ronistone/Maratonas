#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> A;
ll sum,mid;

int dp[30][400];

bool solve(ll current,ll w){
	if(current >= A.size() or w > mid) return w==mid? 1:0;
	if(dp[current][w]!=-1) return dp[current][w];
	
	
	bool ans = solve(current+1,w);
	if(w+A[current] <= mid)
		ans = max(ans,solve(current+1,w+A[current]));
	
	return dp[current][w] = ans;
}

main(){
	int t,aux;
	
	scanf("%d",&t);
	
	
	for(int k=0;k<t;k++){
		
		memset(dp,-1,sizeof dp);
		A.clear();
		sum = 0;
		
		scanf("%d",&aux);
		sum += aux;
		A.push_back(aux);
		while(getchar()!='\n'){
			scanf("%d",&aux);
			sum += aux;
			A.push_back(aux);
		}
		mid = sum/2;
		if(sum%2==0 and solve(0,0))
			printf("YES\n");
		else
			printf("NO\n");
	}



}
