#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll Grafo[101][101];
bool visitados[101];
int m;

main(){
	int n,z,from,to,x,y;
	scanf("%d",&z);
	for(int v =0;v<z;v++){
		scanf("%d", &m);
		scanf("%d", &n);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
					if(i==j)
						Grafo[i][j] = 0;
					else
						Grafo[i][j] = 100000000;
			}
		}
		for(int q=0;q<n;q++){
			scanf("%d %d",&from,&to);
			Grafo[from][to] = 1;
			Grafo[to][from] = 1;
		}
		scanf("%d %d",&x,&y);
		for (int k = 0; k < m; k++){
			for (int i = 0; i < m; i++){
				for (int j = 0; j < m; j++){
					Grafo[i][j] = min(Grafo[i][j], Grafo[i][k] + Grafo[k][j]);
				}
			}
		}
		ll saida = 0;
		for(int i=0;i<m;i++)
			saida = max(Grafo[x][i]+Grafo[i][y],saida);
			
		cout << "Case " << v+1<< ": " << saida << endl;
	}
}
