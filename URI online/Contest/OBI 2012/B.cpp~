#include <bits/stdc++.h>
using namespace std;


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,m,n;
	cin >> m >> n;
	cin.ignore();
	char M[m+1][n+1];
	int costa =0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin >> M[i][j];
			if(M[i][j]=='#')
				costa++;
		}
		cin.ignore();
	}
	for(i=1;i<m-1;i++){
		for(j=1;j<n-1;j++){
			if(M[i-1][j]=='#' and M[i+1][j]=='#' and M[i][j-1]=='#' and M[i][j+1]=='#')
			costa--;
		}
	}
	cout << costa << endl;
}
