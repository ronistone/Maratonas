#include <bits/stdc++.h>
using namespace std;

int n,c;
int dp[200005];
int prices[200005];
void maxProfit(){
	dp[0]=0;
	int maxDiff = -prices[0];
	
	for(int i=0;i<=n;i++){
		dp[i] = max(dp[i-1],prices[i-1]+maxDiff-c);
		maxDiff = max(maxDiff,dp[i-1]-prices[i-1]);
	}
	cout << dp[n] << "\n";
}


main(){
	int i,j;
	
	cin >> n >> c;
	
	for(i=0;i<n;i++){
		cin >> prices[i];
	}
	maxProfit();
}