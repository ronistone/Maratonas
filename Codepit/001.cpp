#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

char lab[501][501];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
bool valid(int x,int y){
	if(x<0 || x >=n) return false;
	if(y<0 || y >=n) return false;
	if(lab[x][y]=='#') return false;
	return true;
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
		bool achou = false;
		for(int i=0;i<4;i++){
			if(valid(x1+dx[i],y1+dy[i])){
				q.push(make_pair(custo+1,make_pair(x1+dx[i],y1+dy[i])));
				lab[x1+dx[i]][y1+dy[i]] = '#';
				achou = true;
			}
		}
		if(!achou and custo > maior)
			maior = custo;
	}
	return maior;
}


main(){
	while(cin >> n >> m and n and m){
		cin.ignore();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> lab[i][j];
			}
			cin.ignore();
		}
		int maior = 0,aux;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(lab[i][j]=='.'){
					aux = bfs(i,j);
					if(aux > maior){
						maior = aux;
					}
				}
			}
		}
		cout << maior << endl;
	}
	
}
