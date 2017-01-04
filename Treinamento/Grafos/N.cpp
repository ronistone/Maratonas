#include <bits/stdc++.h>
#define S second
#define F first
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<iii> viii;
int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};
bool Grafo[1001][1001];
int n,m;

bool valid(int i,int j){
	if(Grafo[i][j]) return false;
	if(i<0 or i>=n) return false;
	if(j<0 or j>=m) return false;
	return true;
}

int bfs(ii ini,ii dest){
	queue<iii> q;
	q.push(make_pair(0,make_pair(ini.F,ini.S)));
	Grafo[ini.F][ini.S]=true;
	while(!q.empty()){
		iii x = q.front();
		ii p = x.second;
		q.pop();
		if(x.second == dest)
			return x.first;
		for(int i=0;i<4;i++){
			if(valid(p.first+dy[i],p.second+dx[i])){
				Grafo[p.first+dy[i]][p.second+dx[i]] = true;
				q.push(make_pair(x.first+1,make_pair(p.first+dy[i],p.second+dx[i])));
			}
		}
	
	}
	
}

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l,c,i,j,k,z,xi,yi,xd,yd,b;
	while(cin >> n >> m and n and m){
		cin >> z;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				Grafo[i][j] = false;
			}
		}
		for(i=0;i<z;i++){
			cin >> l >> b;
			for(j=0;j<b;j++){
				cin >> c;
				Grafo[l][c] = true;
			}
		}
		cin >> xi >> yi;
		cin >> xd >> yd;
		cout << bfs(make_pair(xi,yi),make_pair(xd,yd)) <<"\n";
	}
}

