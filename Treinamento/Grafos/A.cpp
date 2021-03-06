#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int Grafo[101][101];
int r,c,n,m,e,o;
int dx[] = {-1,1,-1,1};
int dy[] = {1,1,-1,-1};
bool valid (int i,int j){
	if(i<0 or i>=r) return false;
	if(j<0 or j>=c) return false;
	if(Grafo[i][j]==2) return false;
	return true;
}
void bfs(){
	queue<ii> Q;
	int visi =0;
	Q.push(make_pair(0,0));
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		int cont=0; 
		for(int i=0;i<4;i++){
			if(valid(x+(dx[i]*m),y+(dy[i]*n)) and ((abs(x - (x+(dx[i]*m)))==m and abs(y- (y+(dy[i]*n)))==n) or (abs(x - (x+(dx[i]*m)))==n and abs(y- (y+(dy[i]*n)))==m))){
			if((x+(dx[i]*m)==0 and y+(dy[i]*n)==0 and visi< (r*c)))
				break;
				cont++;
				if(Grafo[x+(dx[i]*m)][y+(dy[i]*n)]==0){
					Q.push(make_pair(x+(dx[i]*m),y+(dy[i]*n)));
					Grafo[x+(dx[i]*m)][y+(dy[i]*n)] = 1;
					visi++;
				}
			}
			if(valid(x+(dx[i]*n),y+(dy[i]*m)) and ((abs(x - (x+(dx[i]*n)))==m and abs(y- (y+(dy[i]*m)))==n) or (abs(x - (x+(dx[i]*n)))==n and abs(y- (y+(dy[i]*m)))==m))){
				break;
			if((x+(dx[i]*n)==0 and y+(dy[i]*m)==0 and visi< (r*c)))
				cont++;
				if(Grafo[x+(dx[i]*n)][y+(dy[i]*m)]==0){
					Q.push(make_pair(x+(dx[i]*n),y+(dy[i]*m)));
					Grafo[x+(dx[i]*n)][y+(dy[i]*m)] = 1;
					visi++;
				}
			}
		}
		if(cont%2==0)
			e++;
		else
			o++;
	}
}


main(){
	int k,i,j,x,y,w;
	
	cin >> k;
	
	for(i=0;i<k;i++){
		cin >> r >> c >> m >> n;
		cin >> w;
		memset(Grafo,0,sizeof Grafo);
		for(j=0;j<w;j++){
			cin >> x >> y;
			Grafo[x][y] = 2;
		}
		e = 0;
		o = 0;
		bfs();
		cout << "Case " << i+1 << ": " << e-1 << " " << o << "\n";
	}

}
