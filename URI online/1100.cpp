#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define F first
#define S second
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
bool tabuleiro[8][8];
int dx[] = {-2,-1,-2,-1,2,1,2,1};
int dy[] = {-1,-2,1,2,-1,-2,1,2};

bool valid(int x,int y){
	if(x<0 or x>=8) return false;
	if(y<0 or y>=8) return false;
	if(tabuleiro[x][y]) return false;
	return true;
}

int bfs(ii ini,ii dest){
	queue<iii> q;
	q.push(MP(0,ini));
	
	while(!q.empty()){
		int custo = q.front().F;
		int x = q.front().S.F;
		int y = q.front().S.S;
		q.pop();
		if(x==dest.F and y==dest.S)
			return custo;
		for(int i=0;i<8;i++){
			int xi = x+dx[i];
			int yi = y+dy[i];
			if(valid(xi,yi)){
				q.push(MP(custo+1,MP(xi,yi)));
				tabuleiro[xi][yi] = true;
			}
		}
	}
	
}

main(){
	int from,to;
	char cf,ct;
	
	while(scanf("%c%d %c%d",&cf,&from,&ct,&to)!=EOF){
		getchar();
		memset(tabuleiro,false,sizeof(tabuleiro));
		cout << "To get from "
			<< cf << from << " to "
			<< ct << to << " takes "
			<< bfs(MP(from-1,(int)(cf-'a')),MP(to-1,(int)(ct-'a')))
			<< " knight moves.\n";
	}

}
