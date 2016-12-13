#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,m;

	cin >> n >> m;
	int ruas[n][m];

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> ruas[i][j];
		}
	}
	bool achou = false;
	for(i=0;i<n && !achou;i++){
		for(j=0;j<m;j++){
			if(i!=n-1 && j!=m-1 && i!=0 && j!=0){
				if(ruas[i][j]==42){
					if((ruas[i-1][j-1]==7 && ruas[i][j-1]==7) && (ruas[i+1][j-1]==7 && ruas[i+1][j]==7) && (ruas[i-1][j]==7
						 && ruas[i-1][j+1]==7) && (ruas[i][j+1] == 7 && ruas[i+1][j+1]==7)){
						cout << i+1 << " " << j+1 << endl;
						achou = true;
						break;
					}
				}
			}
		}
	}
	if(!achou)
		cout << "0 0" << endl;

}