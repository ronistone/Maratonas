#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
char A[20][110];
bool visitados[20][110];
int n,m,h;

bool valid(int x,int y){
	if(x < 0 or x >= n) return false;
	if(y < 0 or y >= m+2) return false;
	//if(visitados[x][y]) return false;
	return true;
}
ll bfs(int* xd){
	int d,x,hi,y;
	int* da;
	queue<pair<int,pair<int,pair<int*,pair<int,int> > > > > q;
	q.push({0,{h,{xd,{0,0}}}});
	visitados[0][0] = true;
	while(!q.empty()){
		d = q.front().F;
		hi = q.front().S.F;
		x = q.front().S.S.S.F;
		y = q.front().S.S.S.S;
		da = q.front().S.S.F;
		q.pop();
		if(hi==0)
			return d+1;
		for(int i=0;i<n;i++)
			cout << da[i] << "  ";
		cout << endl;
		for(int i=0;i<4;i++){
			int xa = x+dx[i];
			int ya = y+dy[i];
			if(valid(xa,ya) and !((i==0 or i==3) and (y!=0 or y!=m+1))){
				if(i==0 or i==3){
					if(da[x]==0){
						if(A[xa][ya]=='1')
							da[xa]--;
						q.push({d+1,{A[xa][ya]=='1'?hi-1:hi,{da,{xa,ya}}}});
						visitados[xa][ya] = true;
					}
				}
				else{
					if(A[xa][ya]=='1')
							da[xa]--;
						q.push({d+1,{A[xa][ya]=='1'?hi-1:hi,{da,{xa,ya}}}});
						visitados[xa][ya] = true;
				}
			}
		}
		
	}
	
	return -1;
}





main(){
	
	cin >> n >> m;
	h = 0;
	int xd[30];
	memset(xd,0,sizeof xd);
	for(int i=0;i<n;i++){
		cin.ignore();
		cin >> A[i];
		for(int j=0;j<m+2;j++){
			if(A[i][j]=='1'){
				h++;
				xd[i]++;
			}
		}
	}
	cout << bfs(xd) << endl;
	
}
