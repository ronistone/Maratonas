#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char A[105][105];
bool visitados[105][105];
int n,m,h,w,xf,yf;

bool valid(int x,int y){
	if(x < 0 or x >= h) return false;
	if(y < 0 or y >= w) return false;
	if(A[x][y]=='#') return false;
	if(visitados[x][y]) return false;
	return true;
}
int calc(int x,int y){
		return abs(x-xf)+abs(y-yf);
}

ll bfs(int xi,int yi){

	queue<pair<int,pair<int,pair<int,int> > > > q;
	q.push({0,{0,{xi,yi}}});
	int ans = -1,xa,ya;
	
	while(!q.empty()){
		int x = q.front().S.S.F;
		int y = q.front().S.S.S;
		int d = q.front().F;
		int p = q.front().S.F;
		//visitados[x][y] = true;
		q.pop();
		if(A[x][y]=='S')
			ans = max(p,ans);
		for(int i=0;i<4;i++){
			xa = x+dx[i];
			ya = y+dy[i];
			if(valid(xa,ya) and calc(xa,ya)+d <= m){
				q.push({d+1,{A[xa][ya]=='*'?p+1:p,{xa,ya}}});
			}
		}
		
		
	}
	return ans;
}





main(){
	
	while(cin >> n >> m){
		cin >> w >> h;
		int x=-1,y=-1;
		memset(visitados,false,sizeof visitados);
		for(int i=0;i<h;i++){
			cin.ignore();
			cin >> A[i];
				for(int j=0;j<w;j++){
					if(A[i][j]=='R'){
						x = i;
						y = j;
					}
					if(A[i][j]=='S'){
						xf = i;
						yf = j;
					}
				}
		}
		cout << bfs(x,y) << endl;
	}
	
}
