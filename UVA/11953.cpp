#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char a[105][105];
bool v[105][105];
int n,m;
bool valid(int x,int y){
	if(x<0 or x>=n){return false;}
	if(y<0 or y>=n){return false;}
	if(v[x][y]){return false;}
	if(a[x][y]!='x' and a[x][y]!='@'){return false;}
	return true;
}
int entrou;
void floodfill(int x,int y){
	v[x][y]=true;
		if(entrou==1 || entrou==0){
			for(int i=0;i<2;i++){
				if(valid(x+dx[i],y+dy[i])){
					entrou = 1;
					floodfill(x+dx[i],y+dy[i]);
				}
			}
		}
		if(entrou==2 || entrou==0){
			for(int i=2;i<4;i++){
				if(valid(x+dx[i],y+dy[i])){
					entrou = 2;
					floodfill(x+dx[i],y+dy[i]);
				}
			}
		}
}

int main(){
	int i,j;
	
	cin >> m;
	for(int k=0;k<m;k++){
		cin >> n;
		int saida = 0;
		cin.ignore();
		memset(v,false,sizeof(v));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin >> a[i][j];
			}
			cin.ignore();
		}
		int ship = 0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(a[i][j]=='x' and !v[i][j]){
					entrou = 0;
					ship++;
					floodfill(i,j);
				}
			}
		}
		cout << "Case " << k+1 << ": " << ship << endl;
	}

}
