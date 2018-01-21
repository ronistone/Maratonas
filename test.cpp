#include <bits/stdc++.h>

using namespace std;


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n=5,m=5;
bool M[5][5];

bool valid(int x,int y){
	if(x < 0 or x >= 5) return false;
	if(y < 0 or y >= 5) return false;
	if(M[x][y])	return false;
	return true;
}



bool floodfill(int x, int y){
	M[x][y] = true;
	if(x==4 and y==4) return true;
	for(int i=0;i<4;i++){
		if(valid(x+dx[i],y+dy[i]) and floodfill(x+dx[i],y+dy[i]))
			return true;	
	}
	return false;
}

main(){
	
	int k,aux;
	
	cin >> k;
	
	for(int z=0;z<k;z++){
		memset(M,false,sizeof M);
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				cin >> aux;
				if(aux) M[i][j] = true;
				else	M[i][j] = false;
			}
		}
		
		cout << (floodfill(0,0)? "COPS":"ROBBERS") << endl;
	}

}
