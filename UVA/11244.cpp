#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0,-1,-1,1,1};
int dy[] = {0,0,1,-1,-1,1,-1,1};

char a[105][105];
bool v[105][105];
int n,m;
int estrela;
bool valid(int x,int y){
	if(x<0 or x>=n) return false;
	if(y<0 or y>=m) return false;
	if(v[x][y]) return false;
	if(a[x][y]!='*') return false;
	return true;
}
bool entrou;
void floodfill(int x,int y){
	v[x][y]=true;
		for(int i=0;i<8;i++){
			if(valid(x+dx[i],y+dy[i])){
				entrou = true;
				floodfill(x+dx[i],y+dy[i]);
			}
		}
	if(!entrou)
		estrela++;
}

int main(){
	int i,j;
	
	while(cin >> n >> m and n and m){
		int saida = 0;
		cin.ignore();
		memset(v,false,sizeof(v));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin >> a[i][j];
			}
			cin.ignore();
		}
		estrela = 0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j]=='*' and !v[i][j]){
					entrou = false;
					floodfill(i,j);
				}
			}
		}
		cout << estrela << endl;
	}

}
