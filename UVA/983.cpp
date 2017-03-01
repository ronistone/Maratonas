#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	
	int n,m;
	bool prim = true;
	while(cin >> n >> m){
		ll M[n][n];
		ll n1 = (n-m+1) << 1;
		ll ans[n1][n1];
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<n;j++){
				cin >> M[i][j];
//				if(i<n-1)		  M[i][j] += M[i+1][j];
	//			if(j>0)			  M[i][j] += M[i][j-1];
		//		if(i<n-1 and j>0) M[i][j] -= M[i+1][j-1];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i>0)		  	M[i][j] += M[i-1][j];
				if(j>0)			M[i][j] += M[i][j-1];
				if(i>0 and j>0) M[i][j] -= M[i-1][j-1];
			}
		}
		memset(ans,-1,sizeof ans);
		ll atx = 0,aty=0,x,y,i,j;
		for(i=0,x=m-1;i<n;i++,x=i+m-1){
			if(x>=n) break;
			for(j=0,y=m-1;j<n;j++,y=j+m-1){
				if(y>=n) break;
				ans[atx][aty] = M[x][y];
				if(i>0)			  ans[atx][aty] -= M[i-1][y];
				if(j>0)			  ans[atx][aty] -= M[x][j-1];
				if(i>0 and j>0)	  ans[atx][aty] += M[i-1][j-1];
				aty++;
			}
			atx++;
		}
		ll sum = 0;
		if(!prim)
			cout << endl;
		else
			prim = false;
		for(i=n1-1;i>=0;i--){
			for(j=0;j<n1;j++){
				if(ans[i][j]!=-1){
					cout << ans[i][j] << endl;
					sum += ans[i][j];
				}
			}
		}
		cout << sum << endl;
	}

}
