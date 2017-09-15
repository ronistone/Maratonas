#include <bits/stdc++.h>
using namespace std;

main(){
	int n,from,to;
	int G[11][11];
	while(cin >> n){
		for(int i=0;i<=9;i++){ 
			for(int j=0;j<=9;j++)
				G[i][j] = -1000000;
		}
		for(int i=0;i<n;i++){
			cin >> from >> to;
			G[from][to] = 1;
			G[to][from] = 1;
		}
	int ans = 0;
		for(int k=0;k<=9;k++){
			for(int i=0;i<=9;i++){
				for(int j=0;j<=9;j++){
					G[i][j] = max(G[i][j],G[i][k]+G[k][j]);
					G[j][i] = G[i][j];
					//ans = min(ans,G[i][j]);
				}
			}
		}
		for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++)
				cout << G[i][j] << " ";
			cout << endl;
		}
		cout << ans << endl;
	}

}
