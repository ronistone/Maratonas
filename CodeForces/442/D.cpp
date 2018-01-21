#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
typedef long long  int ll;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int xf,yf,n,m,k;
char M[1010][1010];

bool valid(int x,int y){
	if(x > n or x <= 0) return false;
	if(y > m or y <= 0) return false;
	if(M[x][y] == '#') return false;
	return true;	
}

ll solve(int x, int y,int c,int d){
	
	if(x==xf and y==yf) return 1;
	M[x][y] = '#';
	ll ans = 100000000000000000;
	for(int i=0;i<4;i++){
		int xa = x+dx[i];
		int ya = y+dy[i];
		if((c+1 > k or (d!=-1 and d!=i)) and valid(xa,ya)){
			ans = min(ans,solve(xa,ya,1,i)+1);
		}
		else if(c+1 <= k and valid(xa,ya) and (d==-1 or d==i)){
			ans = min(ans,solve(xa,ya,c+1,i));
		}
	}
	return ans;
}



main(){
	int xi,yi;
	cin >> n >> m >> k;
	
	//cin.ignore();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> M[i][j];
			//cin.ignore();
		}
	}
	
	cin >> xi >> yi >> xf >> yf;
	if(xi==xf and yf==yi) cout << 0 << endl;
	else{
		ll ans = solve(xi,yi,0,-1);
		cout << (ans>=100000000000000000? -1: ans) << endl;
	}

}
