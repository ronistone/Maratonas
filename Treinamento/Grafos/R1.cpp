#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll Grafo[501][501];
char id[501][501];
int m;

main(){
	int w,i,j,n,m;
	char d,z,from,from1,to;
	
	cin >> n;
	cin.ignore();
	for(i=0;i<500;i++){
		for(j=0;j<500;j++){
				Grafo[i][j]=100000000;
		}
	}
	memset(id,false,sizeof id);
	m = 0;
	for(i=0;i<n;i++){
		cin >> z >> d >> from >> to >> w;
		cin.ignore();
		m = max((int)from-'A',max((int)to-'A',m));
		Grafo[(int)from-'A'][(int)to-'A'] = w;
		id[(int)from-'A'][(int)to-'A'] = z;
		if(d=='B')
			Grafo[(int)to-'A'][(int)from-'A'] = w, id[(int)from-'A'][(int)to-'A'] = z;
	}
	for (int k = 0; k < m; k++){
		for (int i = 0; i < m; i++){
			for (int j = 0; j < m; j++){
				if(Grafo[i][j] > Grafo[i][k] + Grafo[k][j] and id[i][k]==id[k][j])
					Grafo[i][j] = min(Grafo[i][j], Grafo[i][k] + Grafo[k][j]);
			}
		}
	}
	cin >> from >> from1;
	ll saida = 100000000;
	int c = -1;
	for(i=0;i<m;i++){
		if(Grafo[(int)from-'A'][i]+Grafo[(int)from1-'A'][i] < saida){
			saida = Grafo[(int)(from-'A')][i]+Grafo[i][(int)(from1-'A')];
			c = i;
		}
	}
	cout << saida << " " << (char)(c+'A') << endl;
	
			
}
