#include <bits/stdc++.h>
using namespace std;
int t,n;
int A[20];
unordered_map<int,bool> ans;
unordered_map<int,bool>::iterator it;
int dp[5000];

int solve(int current,int sum,int mask){
	if(sum==t){
		ans[mask] = true;
		return 1;
	}
	if(sum > t or current >=n) return 0;
	if(dp[mask]!=-1) return dp[mask];
	
	int a = solve(current+1,sum+A[current],mask | 1 << current);
	//cout << current << endl;
	a = max(a,solve(current+1,sum,mask));
	return dp[mask] = a;
}

main(){
	string e;
	vector<string> x;
	while(cin >> t >> n and n){
		for(int i=0;i<n;i++)
			cin >> A[i];
			
		memset(dp,-1,sizeof dp);
		solve(0,0,0);
		cout << "Sums of " << t << ":" << endl;
		bool achou;
		map<string,bool> mapa;
		map<string,bool>::iterator it1;
		for(it=ans.begin();it!=ans.end();it++){
			achou = false;
			e = "";
			for(int i=0;i<n;i++){
				if(it->first & (1 << i)){
					if(achou)
						e+= "+";
					achou = true;
					e += to_string(A[i]);
				}
			}	
			mapa[e] = true;
		}
		for(it1= mapa.begin();it1!=mapa.end();it1++)
			x.push_back(it1->first);
		for(int i=x.size()-1;i>=0;i--){
			 cout << x[i] << endl;
		}
		if(!x.size())
			cout << "NONE" << endl;
		x.clear();
		mapa.clear();
		ans.clear();
	}

}
