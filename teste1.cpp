#include <bits/stdc++.h>
using namespace std;

int pontos[1010][1010],X,Y;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct data{
	int x,y;
	int d,ini;
	data(int x_,int y_,int d_,int ini_): x(x_), y(y_), d(d_), ini(ini_) {}
};
inline int calc(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
inline bool valid(int x,int y){
	if(y < 0 or y >= Y) return false;
	if(x < 0 or x >= X) return false;
	return true;
}
inline bool compare(data a,data b){
	return a.ini == b.ini? a.d > b.d: a.ini < b.ini;
}
int bfs(int x,int y, int d){
	queue<pair<int,pair<int,int> > > q;
	bool visi[X][X];
	memset(visi,false,sizeof visi);
	q.push(make_pair(0,make_pair(x,y)));
	visi[x][y] = true;
	
	while(!q.empty()){
	
		int dis = q.front().first;
		int xi = q.front().second.first;
		int yi = q.front().second.second;
		q.pop();
		
		if(pontos[xi][yi] == 2)
			return dis;
			
		for(int i=0;i<4;i++){
			int xa = xi+dx[i];
			int ya = yi+dy[i];
			if(!visi[xa][ya] and valid(xa,ya) and dis+1 < d){
				visi[xa][ya] = true;
				q.push(make_pair(dis+1,make_pair(xa,ya)));
			}
		}
	
	}

	return d;
}

pair<int,int> dijkstra(int xi,int yi, int xf, int yf,int d){
	
	priority_queue<data, vector<data> , function<bool(data,data)> > pq(compare);
	pontos[xi][yi] = 1;
	pq.push(data(xi,yi,0,d));
	
	while(!pq.empty()){
		int dis = pq.top().d;
		int xv = pq.top().x;
		int yv = pq.top().y;
		int ini = pq.top().ini;
		pq.pop();
		
		if(xv == xf and yv==yf)
			return make_pair(ini,dis);
			
		for(int i=0;i<4;i++){
			int xa = xv+dx[i];
			int ya = yv+dy[i];
			if(pontos[xa][ya]==0 and valid(xa,ya)){
				pontos[xa][ya] = 1;
				pq.push(data(xa,ya,dis+1,bfs(xa,ya,ini)));
			}
		}
	}
	
}


main(){

	int k,n,xi,yi,xf,yf,d,x,y;
	
	
	cin >> k;
	
	
	for(int z=0;z<k;z++){
		memset(pontos,0,sizeof pontos);
		cin >> n >> X >> Y;
		
		cin >> xi >> yi >> xf >> yf;
		d = 10101010;
		pair<int,int> aux = make_pair(xi,yi);
		for(int i=0;i<n;i++){
			cin >> x >> y;
			pontos[x][y] = 2;
			d = min(d,calc(make_pair(x,y),aux));
		}
		pair<int,int> ans = dijkstra(xi,yi,xf,yf,d);
		cout << ans.first << " " <<  ans.second << endl;
	}



}
