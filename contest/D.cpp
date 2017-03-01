#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second


typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;
int n;
ll matriz[500][500];
int dx[] = {1,-1,0,0,1,-1,-1,1};
int dy[] = {0,0,1,-1,1,1,-1,-1};

bool valid(int x,int y){
		if(x<0 or x>n) return false;
		if(y<0 or y>n) return false;
		if(matriz[x][y]!=-1) return false;
		return true;
}

void bfs(){
		queue<iiii> Q;
		Q.push(mp(mp(1,1),mp(floor(n/2.0),floor(n/2.0))));
		
		while(!Q.empty()){
			ii coord = Q.front().second;
			ii prof = Q.front().first;
			Q.pop();
			matriz[coord.F][coord.S] = prof.F;
			for(int i= 0;i<8;i++){
					int x = coord.F+dx[i];
					int y = coord.S+dy[i];
					if(valid(coord.F,coord.S)){
						Q.push(mp(mp(prof.F+prof.S,prof.S+1),mp(x,y)));
					}
			}
		}
}

main(){
	int z;
	
	cin >> z;
	
	for(int i=0;i<z;i++){
			cin >> n;
			n = n+(n-1);
			memset(matriz,-1,sizeof(matriz));
			bfs();
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
						cout << matriz[i][j];
						if(j!=n-1)
							cout << " ";
				}
				cout << endl;
			}
			cout << endl;
	}
	
}
