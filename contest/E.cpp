#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int dx[] = {1,-1,0,0,1,-1,-1,1};
int dy[] = {0,0,1,-1,1,1,-1,-1};

char m[3][3];
bool visi[3][3];

bool verifica(){
		for(int i=0;i<3;i++){
			if(m[0][i]=='1' and m[1][i]=='1' and m[2][i]=='1')
				return true;
			else if(m[i][0]=='1' and m[i][1]=='1' and m[i][2]=='1')
				return true;
		}
		if(m[0][0]=='1' and m[1][1]=='1' and m[2][2]=='1')
			return true;
		if(m[0][2]=='1' and m[1][1]=='1' and m[2][0]=='1')
			return true;
		
		return false;
}
bool valid(ii t){
		if(t.first<0 or t.first>=3) return false;
		if(t.second<0 or t.second>=3) return false;
		return true;
}

main(){
	queue<iii> Q;
	while(cin >> m[0][0]){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(not (i==j and i==0)){
					cin >> m[i][j];
				}
					if(m[i][j]=='1')
						Q.push(make_pair(0,make_pair(i,j)));
			}
			cin.ignore();
		}
		memset(visi,false,sizeof(visi));
		bool P = false;
		while(!Q.empty()){
			ii t = Q.front().second;
			int v = Q.front().first;
			Q.pop();
			if(v==0){
				visi[t.first][t.second] = true;
			}
			bool a = false;
			if(m[t.first][t.second]!='1')
				m[t.first][t.second] = '1';
			else
				a = true;
			if(verifica()){
					P = true;
					break;
			}
			if(!a)
				m[t.first][t.second] = '0';
			if(v==0){
			for(int i=0;i<8;i++){
				t.first += dx[i];
				t.second += dy[i];
				if(valid(t) and !visi[t.first][t.second]){
					Q.push(make_pair(1,make_pair(t.first,t.second)));
				}
			}
			}
		}
		if(P)
			cout << "SIM\n";
		else
			cout << "NAO\n";
		while(!Q.empty())
			Q.pop();
		
	}
}
