#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0,-1,-1,1,1};
int dy[] = {0,0,1,-1,-1,1,-1,1};

char a[105][105];
bool v[105][105];
int n,m;
bool valid(int x,int y){
	if(x<0 or x>=n) return false;
	if(y<0 or y>=m) return false;
	if(v[x][y]) return false;
	if(a[x][y]!='@') return false;
	return true;
}
void floodfill(int x,int y){
	v[x][y]=true;
		for(int i=0;i<8;i++){
			if(valid(x+dx[i],y+dy[i])){
				floodfill(x+dx[i],y+dy[i]);
			}
		}
}

int main(){
	int i,j;
	
	while(cin >> n >> m and n){
		int saida = 0;
		cin.ignore();
		memset(v,false,sizeof(v));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin >> a[i][j];
			}
			cin.ignore();
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i][j]=='@' and !v[i][j]){
					saida++;
					floodfill(i,j);
				}
			}
		}
		cout << saida << endl;
	}

}
