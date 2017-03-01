#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ll n;
	
	cin >> n;
	
	ll M[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> M[i][j];
			if(i>0) M[i][j] += M[i-1][j];
			if(j>0) M[i][j] += M[i][j-1];
			if(i>0 and j>0) M[i][j] -= M[i-1][j-1];
		}
	}
	
	ll MAX = -127*100*100;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int x=i;x<n;x++){
				for(int y=j;y<n;y++){
					ll at = M[x][y];
					if(i>0) at -= M[i-1][y];
					if(j>0) at -= M[x][j-1];
					if(j>0 and i>0) at += M[i-1][j-1];
					MAX = max(at,MAX);
				}
			}
		}
	}
	cout << MAX << endl;
}
