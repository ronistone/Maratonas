#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	
	while(cin >> n >> m and n and m){
		ll M[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> M[i][j];
				if(M[i][j]==1)
					M[i][j] = -100;
				else
					M[i][j] = 1;
				if(i>0) M[i][j] += M[i-1][j];
				if(j>0) M[i][j] += M[i][j-1];
				if(i>0 and j>0) M[i][j] -= M[i-1][j-1];
			}
		}
		ll ans = -100*100*100;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int x=i;x<n;x++){
					for(int y=j;y<m;y++){
						ll at = M[x][y];
						if(i>0) at -= M[i-1][y];
						if(j>0) at -= M[x][j-1];
						if(j>0 and i>0) at += M[i-1][j-1];
						ans = max(at,ans);
					}
				}
			}
		}
		if(ans > 0)
			cout << ans << endl;
		else cout << 0 << endl;
	}
	
}
