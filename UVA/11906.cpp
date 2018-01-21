#include <bits/stdc++.h>
using namespace std;


int mapa[105][105],par,impar,n,m,r,c;
int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,-1,1};
bool valid(int x, int y){
	if(x < 0 or x >= r) return false;
	if(y < 0 or y >= c) return false;
	if(mapa[x][y] == 2) return false;
	return true;
}

void bfs(){
	
	queue<pair<int,int> > q;
	q.push(make_pair(0,0));
	int x,y,aux=0,xa,ya;
	mapa[0][0] = 1;
	
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		cout << x << "," << y << endl;
		q.pop();
		aux = 0;
		for(int i=0;i<4;i++){
			xa = x+(dx[i]*m);
			ya = y+(dy[i]*n);
			if(valid(xa,ya)){
				aux++;
				if(!mapa[xa][ya]){
					q.push(make_pair(xa,ya));
					mapa[xa][ya] = 1;
				}
			}
		}
		if(aux%2)
			par++;
		else
			impar++;
		
	}
	
}


main(){

	int t,y,w,x;
	
	cin >> t;
	
	
	for(int k=0;k<t;k++){
		cin >> r >> c >> m >> n;
		memset(mapa,0,sizeof mapa);
		cin >> w;
		for(int i=0;i<w;i++){
			cin >> x >> y;
			
			mapa[x][y] = '2';
		}
		par = impar = 0;
		bfs();
		
		cout << "Case " << k+1 << ": " << par << " " << impar << endl;
	}
}
