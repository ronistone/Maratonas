#include <bits/stdc++.h>
using namespace std;


main(){
	int m,n,z,k,i,j,from,to;
	
	
	cin >> z;
	
	for(int v =0;v<z;v++){
		cin >> m;
		cin >> n;
		vector<vector<long long int> > Grafo(m,(m,LLONG_MAX));
		for(int q=0;q<n;q++){
			cin >> from >> to;
			Grafo[from][to] = 1;
		}
		for (int k = 0; k < V; k++){
			for (int i = 0; i < V; i++){
				for (int j = 0; j < V; j++){
					Grafo[i][j] = min(Grafo[i][j], Grafo[i][k] + Grafo[k][j]);
				}
			}
		}
		for(int q = 0;q < m;q++){
			cout << Grafo[2][q] << endl;
		}
	}
}
