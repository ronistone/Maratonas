#include <bits/stdc++.h>
using namespace std;

int dn[] = {-1,1,0,0,1,-1,-1,1};
int dm[] = {0,0,-1,1,1,1,-1,-1};
bool visitados[201][201];
int n,m;
bool valid(int i,int j){
	if(i<0 or i>=n) return false;
	if(j<0 or j>=m) return false;
	if(visitados[i][j]) return false;
	return true;
}
int saida;

void floodfill(int i,int j){
	visitados[i][j]=true;
	saida++;
	for(int k=0;k<8;k++){
		if(valid(i+dn[k],j+dm[k]))
			floodfill(i+dn[k],j+dm[k]);
	}
}

main(){
	int i,j,x,y,k,x1,y1;
	
	cin >> n >> m >> x >> y >> k;
	memset(visitados,false,sizeof(visitados));
	for(i=0;i<k;i++){
		cin >> x1 >> y1;
		visitados[x1-1][y1-1] = true;
	}
	saida = 0;
	floodfill(x-1,y-1);
	cout << saida << '\n';
}
