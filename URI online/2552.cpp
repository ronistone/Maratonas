#include <bits/stdc++.h>
using namespace std;

int A[101][101];

main(){
	int n,m,aux;
	while(cin >> n >> m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> aux;
				A[i][j] = aux==1? 9:0;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(A[i][j]!=9){
					if(i>0) A[i][j] += A[i-1][j] == 9? 1:0;
					if(i<n-1) A[i][j] += A[i+1][j] == 9? 1:0;
					if(j>0) A[i][j] += A[i][j-1] == 9? 1:0;
					if(j<m-1) A[i][j] += A[i][j+1] == 9? 1:0;
				}
				cout << A[i][j];
			}
			cout << endl;
		}
	}

}
