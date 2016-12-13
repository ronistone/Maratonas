#include <bits/stdc++.h>
using namespace std;

int n,m;
string grafo[1030];

void dfs(int i,int j){
	grafo[i][j] = 'o';
	
	if(i>0 and grafo[i-1][j]!='o')
			dfs(i-1,j);
	if(i<n-1 and grafo[i+1][j]!='o')
		dfs(i+1,j);
	if(j>0 and grafo[i][j-1]!='o')
			dfs(i,j-1);
	if(j<m-1 and grafo[i][j+1]!='o')
			dfs(i,j+1);
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		int i,j;
		int saida = 0;
		cin >> n >> m;
		cin.ignore();
		for(i=0;i<n;i++){
				getline(cin,grafo[i]);
		}
		for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(grafo[i][j]!='o'){
						saida++;
						dfs(i,j);
					}
				}
		}
		cout << saida << endl;
}
