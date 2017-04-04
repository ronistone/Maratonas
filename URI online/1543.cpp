#include  <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n,m,z;
int A[105][105];
string P[105];
int dp[105][105][105];


int solve(int current,int ant,int posi){

	if(current >= n or posi >= n) return 0;
	
	if(dp[current][ant][posi]!=-1) return dp[current][ant][posi];

	bool block = false;
	int sum = 0;
	for(int i=0;i<P[current].size();i++){
		if((P[ant][i]=='.' and P[current][i]=='.') or P[current][i]!=P[ant][i]){
			if(P[current][i]=='+')
				sum += A[posi][i];
			else if(P[current][i]=='-')
				sum -= A[posi][i];
		}
		else{
			block = true;
			break;
		}	
	}
	int ans = -10000000;
		for(int i=1;i<=z;i++){
			if(!block)
				ans = max(ans,solve(i,current,posi+1)+sum);
			else if(i!=current)
				ans = max(ans,solve(i,ant,posi));
		}
		//ans = solve(current+1,ant,posi);
		//	ans = max(ans,solve(current,current,posi+1)+sum);
	
	return dp[current][ant][posi] = ans;
}


main(){
	
	while(cin >> n >> m and n and m){
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> A[i][j];
	
		cin >> z;
		cin.ignore();
		P[0] = string(m,'.');
		for(int i=1;i<=z;i++)
			getline(cin,P[i]);
			
		memset(dp,-1,sizeof dp);
		cout << solve(1,0,0) << endl;
		
	}
	

}
