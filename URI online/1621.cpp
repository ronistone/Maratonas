#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

char lab[501][501];
bool v[501][501];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
bool valid(int x,int y){
	if(x<0 || x >=n) return false;
	if(y<0 || y >=m) return false;
	if(lab[x][y]=='#') return false;
	if(v[x][y]) return false;
	return true;
}
int xf,yf,maior;
void imprime(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << lab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void dfs(int x,int y,int c){
	v[x][y] = true;
	int x1,y1;
	
	if(c>maior){
		maior = c;
		xf = x;
		yf = y;
	}
	
	for(int i =0;i<4;i++){
		x1 = x+dx[i];
		y1 = y+dy[i];
		if(valid(x1,y1)){
			dfs(x1,y1,c+1);
		}
	}

}

int bfs(int x,int y){
	
	queue<iii>q;
	q.push(make_pair(0,make_pair(x,y)));
	int maior = 0;
	
	while(!q.empty()){
		int custo = q.front().first;
		int x1 = q.front().second.first;
		int y1 = q.front().second.second;
		q.pop();
		int achou = 0;
		for(int i=0;i<4;i++){
			if(valid(x1+dx[i],y1+dy[i])){
				if(!v[x1+dx[i]][y1+dy[i]]){
					q.push(make_pair(custo+1,make_pair(x1+dx[i],y1+dy[i])));
					v[x1+dx[i]][y1+dy[i]] = true;
					//cout << custo << endl;
					//imprime();
				}
				achou++;
			}
		}
		if(achou<=1 and custo > maior)
			maior = custo;
	}
	return maior;
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j;
	while(cin >> n >> m and n and m){
		maior = 0;
		cin.ignore();
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin >> lab[i][j];
			}
			cin.ignore();
		}
		memset(v,false,sizeof(v));
		int ma = 0,aux;
		bool achou = false;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(lab[i][j]=='.'){
					dfs(i,j,0);
					achou = true;
					break;
				}
			}
			if(achou)
				break;
		}
		memset(v,false,sizeof(v));
		dfs(xf,yf,0);
		cout << maior << endl;
	}
}
