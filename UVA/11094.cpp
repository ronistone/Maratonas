#include <bits/stdc++.h>
using namespace std;

char a[25][25];
bool visitado[25][25];
int maior,n,m;
char mark;
void floodfill(int x,int y){
	
	maior++;
	visitado[x][y] = true;
		
	if(x-1>=0 and a[x-1][y]==mark and !visitado[x-1][y])
		floodfill(x-1,y);
		
	if(x+1<n and a[x+1][y]==mark and !visitado[x+1][y])
		floodfill(x+1,y);
		
	if(y-1>=0 and a[x][y-1]==mark and !visitado[x][y-1])
		floodfill(x,y-1);

	if(y+1<m and a[x][y+1]==mark and !visitado[x][y+1])
		floodfill(x,y+1);

	if(y==0 and a[x][m-1]==mark and !visitado[x][m-1])
		floodfill(x,m-1);

	if(y==m-1 and a[x][0]==mark and !visitado[x][0])
		floodfill(x,0);
}

main(){
	int i,j,x,y;
		
	while(cin >> n >> m){
		int saida = 0;
		memset(visitado,false,sizeof(visitado));
		cin.ignore();
		for(i=0;i<n;i++){
				for(j=0;j<m;j++){
						cin >> a[i][j];
				}
				cin.ignore();
		}
		cin >> x >> y;
		cin.ignore();
		mark = a[x][y];
		floodfill(x,y);
		
		for(i=0;i<n;i++){
				for(j=0;j<m;j++){
					if(a[i][j]==mark && !visitado[i][j]){
						maior = 0;
						floodfill(i,j);
						if(maior> saida)
							saida = maior;
					}
				}
		}
		
		cout << saida << endl;
	}
}conn
