#include <bits/stdc++.h>
using namespace std;

int T[505][505][2];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,p,x,y;
	int Ap,Ab;
	cin >> n >> p;
	memset(T,0,sizeof T);
	
	for(int i=0;i<p;i++){
		cin >> x >> y;x--;y--;
		T[x][y][0] = 1;				// 0  ---> pretas
	}
	for(int i=0;i<p;i++){
		cin >> x >> y;x--;y--;
		T[x][y][1] = 1;				// 1  ---> Brancas
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>0){
				T[i][j][0] += T[i-1][j][0];
				T[i][j][1] += T[i-1][j][1];
			}
			if(j>0){
				T[i][j][0] += T[i][j-1][0];
				T[i][j][1] += T[i][j-1][1];
			}
			if(i>0 and j>0){
				T[i][j][0] -= T[i-1][j-1][0];
				T[i][j][1] -= T[i-1][j-1][1];
			}
		}
	}
	int preta = 0;
	int branca = 0;
	for(int s=1;s<=n;s++){
		//cout << "S:  " << s << endl;
		for(int i=0;i<=n-s;i++){
			for(int j=0;j<=n-s;j++){
				Ap = T[i+s-1][j+s-1][0];
				Ab = T[i+s-1][j+s-1][1];
				if(i>0){Ap -= T[i-1][j+s-1][0]; Ab -= T[i-1][j+s-1][1];}
				if(j>0){Ap -= T[i+s-1][j-1][0]; Ab -= T[i+s-1][j-1][1];}
				if(i>0 and j>0){Ap += T[i-1][j-1][0]; Ab += T[i-1][j-1][1];}
				if(Ap and !Ab) preta++;
				else if(!Ap and Ab) branca++;
			}
		}
	}
	
	
	cout << preta << " " << branca << endl;

}
