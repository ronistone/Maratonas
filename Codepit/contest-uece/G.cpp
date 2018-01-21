#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;
ll A[110][110];


main(){
	
	ll a,b,d,n,m;
	vector<ll> ans1;
	ll ans,sum;
	
	while(cin >> n >> m and (n or m)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				A[i][j] = INT_MAX;
			}
			A[i][i] = 0;
		}
		for(int i=0;i<m;i++){
			cin >> a >> b >> d;
			
			A[a][b] = min(A[a][b],d);
			A[b][a] = min(A[b][a],d);
		}
		
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
				} 
			}
		}
		ans = LLONG_MAX;
		for(int i=1;i<=n;i++){
			sum = 0;
			for(int j=1;j<=n;j++){
				sum += A[i][j];
			}
			if(sum < ans){
				ans = sum;
				ans1.clear();
				ans1.push_back(i);
			}
			else if(sum == ans)
				ans1.push_back(i);
		}
		sort(ans1.begin(),ans1.end());
		for(int i=0;i<ans1.size();i++){
			cout << ans1[i] << " ";
		}
		cout << endl;
		ans1.clear();
	}
	


}
