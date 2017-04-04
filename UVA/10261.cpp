#include <bits/stdc++.h>
using namespace std;

int w;
vector<int> car;
int dp[10001][10001];
int solve(int current,int s1,int s2){
	if(current>=car.size())return dp[s1][s2] = 0LL;
	
	if(dp[s1][s2]!=-1) return dp[s1][s2];
	
	int ans = 0;
	if(car[current]+s1 <= w)
		ans = max(solve(current+1,s1+car[current],s2)+1,ans);
	if(car[current]+s2 <= w)
		ans = max(solve(current+1,s1,s2+car[current])+1,ans);
	
	return dp[s1][s2] = ans;
}
void print(int current, int s1, int s2){
	
	
	if(current>=car.size()) return;
	if(s1+car[current] <=w and dp[s1][s2] - 1 == dp[s1+car[current]][s2]){
		printf("port\n");
		print(current+1,s1+car[current],s2);
	}
	else if(s2+car[current] <=w and dp[s1][s2]-1 == dp[s1][s2+car[current]]){
		printf("starboard\n");
		print(current+1,s1,s2+car[current]);
	}
	
}

main(){
	int n,aux;
	
	scanf("%d",&n);
	
	for(int k=0;k<n;k++){
		scanf("%d",&w);
		w*=100;
		while(scanf("%d",&aux) and aux){
			car.push_back(aux);
		}
		memset(dp,-1,sizeof dp);
		printf("%d\n",solve(0,0,0));

		print(0,0,0);
		car.clear();
		if(k<n-1)
			puts("");
	}


}
