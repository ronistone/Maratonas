#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

int M[55][55][2];
int A[55][55];

main(){
	ll at,n,m;

	cin >> n >> m;
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> A[i][j];
			if(A[i][j]){
				M[i][j][1] = 1;
				M[i][j][0] = 0;
			}
			else{
				M[i][j][0] = 1;
				M[i][j][1] = 0;
			}
			if(i){ M[i][j][0] += M[i-1][j][0]; M[i][j][1] += M[i-1][j][1];}
			if(j){ M[i][j][0] += M[i][j-1][0]; M[i][j][1] += M[i-1][j-1][1];}
			if(i and j){ M[i][j][0] -= M[i-1][j-1][0]; M[i][j][1] -= M[i-1][j-1][1];}
			
		}
	}
	ll ans = 0;
	
	for(int l=0;l<2;l++){
		for(int i=0;i<n;i++){
			at += M[i][m-1][l];
			if(i)
				at -= M[i-1][m-1][l];
			for(int k=m-1;k>=0;k--){
				if(A[i][k]==l)
					ans+= (1 << (m-1-k));
			}
		}
		for(int i=0;i<m;i++){
			at += M[n-1][i][l];
			if(i)
				at -= M[n-1][i-1][l];
			for(int k=n-1;k>=0;k--){
				if(A[k][i]==l)
					ans+= (1 << (n-1-k));
			}
		}
	}
	cout << ans <<  endl;
}
