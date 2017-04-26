#include <bits/stdc++.h>
using namespace std;


main(){
	int z,n,m,at;
	int A[30][30];
	int N[40];
	vector<vector<pair<int,int> > > P(40);
	cin >> z;
	
	for(int k=0;k<z;k++){
		
		cin >> n >> m;
		for(int i=0;i<n+m;i++)
			P[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				A[i][j] = abs(i-1) + abs(j-1);
				P[A[i][j]].push_back(make_pair(i,j));
			}
		}
		at = n*m;
		for(int i=0;i<n+m;i++){
			for(int j=P[i].size()-1;j>=0;j--){
				A[P[i][j].first][P[i][j].second] = at;
				at--;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		
	}
}
