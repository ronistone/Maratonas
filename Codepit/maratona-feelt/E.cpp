#include <bits/stdc++.h>
using namespace std;

string A[200];
int n;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool valid(int x, int y){
	if(x < 0 or x >= n) return false;
	if(y < 0 or y >= n) return false;
	return true;
}

int solve(int x,int y,map<char,bool> visi){
	if(x == n-1 and y == n-1) return 0;
	int ans = 10101010;
	visi[A[x][y]] = true;
	for(int i=0;i<4;i++){
		int xa = x+dx[i];
		int ya = y+dy[i];
		if(valid(xa,ya) and !visi.count(A[xa][ya])){
			ans = min(solve(xa,ya,visi)+1,ans);
		}
	}
	return ans;
}



main(){
	
	
	cin >> n;
	cin.ignore();
	
	for(int i=0;i<n;i++){
		getline(cin,A[i]);
		for(int j=0;j<A[i].size();j++){
			if(A[i][j] >= 'A' and A[i][j] <= 'Z'){
				A[i][j] -= ('A' - 'a');
			}
		}
	}
	map<char,bool> aux;
	int ans = solve(0,0,aux);
	if(ans == 10101010)
		cout << -1 << endl;
	else
		cout << ans << endl;

}
