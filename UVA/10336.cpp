#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
map<char,int> mapa;
char a[305][305];
bool v[305][305];
int n,m;
int estrela;
bool valid(int x,int y,char c){
	if(x<0 or x>=n) return false;
	if(y<0 or y>=m) return false;
	if(v[x][y]) return false;
	if(a[x][y]!=c) return false;
	return true;
}
void floodfill(int x,int y,char c){
	v[x][y]=true;
		for(int i=0;i<4;i++){
			if(valid(x+dx[i],y+dy[i],c)){
				floodfill(x+dx[i],y+dy[i],c);
			}
		}
}
bool ordem(pair<char,int>i,pair<char,int>j){
	if(j.second>i.second) return false;
	else if(j.second<i.second) return true;
	else{
		if(j.first<i.first) return false;
		else return true;
	}
}

int main(){
	int i,j,z,k;
	cin >> z;
	vector<pair<char, int>> saida;
	for(k=0;k<z;k++){
		cin >> n >> m;
		cin.ignore();
		memset(v,false,sizeof(v));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin >> a[i][j];
			}
			cin.ignore();
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(!v[i][j]){
					mapa[a[i][j]]++;
					floodfill(i,j,a[i][j]);
				}
			}
		}
		map<char,int>::iterator it;
		for(it=mapa.begin();it!=mapa.end();it++){
			saida.push_back(make_pair(it->first,it->second));
		}
		sort(saida.begin(),saida.end(),ordem);
		
		cout << "World #" << k+1 << endl;
		for(i=0;i<saida.size();i++){
			cout << saida[i].first << ": " << saida[i].second << endl;
		}
		mapa.clear();
		saida.clear();
	}

}
