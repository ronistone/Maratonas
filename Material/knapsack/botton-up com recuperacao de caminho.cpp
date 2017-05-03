#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w,T;
ll wt[40];
ll A[40][40];
int n;

inline ll knapsack(){
	
	ll K[n+1][T+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=T;j++){
			if(i==0 or j==0)
				K[i][j] = 0;
			else if(A[i-1][1] <= j){
				K[i][j] = max(A[i-1][0]+K[i-1][j-A[i-1][1]],K[i-1][j]);
			}
			else
				K[i][j] = K[i-1][j];
		}
	}
	ll total_B = 0;
	ll total_w = 0;
	vector<pair<ll,ll> > V;
	for(int i=n,j=T;i>0;i--){
		if(K[i][j]!=K[i-1][j]){
			V.push_back(make_pair(wt[i-1],A[i-1][0]));
			++total_B;
			j-=A[i-1][1];
		}
	}
	cout << K[n][T] << endl
		 << total_B << endl;
	for(int i=V.size()-1;i>=0;i--)
		cout << V[i].first << " " << V[i].second << endl;
}
main(){
	bool f = true;
	while(cin >> T >> w){
		if(!f)
			cout << endl;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> A[i][1] >> A[i][0];
			wt[i] = A[i][1];
			A[i][1] = (2*w*A[i][1]) + (w*A[i][1]);
		}
		knapsack();
		f = false;
	}


}
