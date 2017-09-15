#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
typedef long long int ll;

pair<double,double> M[10];
double A[10][10];
double dp[10][1<<10];
vector<string> path;
int n;
inline double calc(int i,int j){
	return sqrt( ((M[i].F-M[j].F)*(M[i].F-M[j].F)) + ((M[i].S-M[j].S)*(M[i].S-M[j].S)) );
}
inline double solve(int current ,int mask){
	if(mask == (1 << n)-1) return 0.0;
	if(dp[current][mask]!=-1) return dp[current][mask];
	
	double ans = 10000;
	
	for(int i=0;i<n;i++){
		if(!(mask & 1 << i))
			ans = min(ans,solve(i,mask | 1 << i)+A[current][i]+16.0);
	}
	return dp[current][mask] = ans;
}
inline void print(int current,int mask){
	if(mask == (1<<n)-1) return;
	double ans = 10000;
	for(int i=0;i<n;i++){
		if(!(mask & 1 << i)){
			if(dp[current][mask] == solve(i,mask | 1 << i)+A[current][i]+16.0){
				print(i,mask | 1 << i);
				cout << fixed << setprecision(2) << "Cable requirement to connect (" << (int) M[i].F << "," <<(int) M[i].S 
					 << ") to (" << (int)M[current].F << "," << (int)M[current].S << ") is " 
					 << A[current][i]+16 << " feet." << endl;
				return;
			}
		}
	}
	
}

main(){
	int cont = 1;
	while(cin >> n and n){
		cout << "**********************************************************" << endl
			 << "Network #" << cont++ << endl;
		for(int i=0;i<n;i++){
			cin >> M[i].F >> M[i].S;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				A[i][j] = calc(i,j);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j < (1 << n);j++){
				dp[i][j] = -1;
			}
		}
		double ans = 10000;
		int mini = 0;
		for(int i=0;i<n;i++){
			ans = min(ans,solve(i,1 << i));
			if(ans == solve(i,1<<i))
				mini = i;
		}
		print(mini, 1 << mini);
		cout << fixed << setprecision(2) << "Number of feet of cable required is " << ans << "." << endl;
		
	}

}
