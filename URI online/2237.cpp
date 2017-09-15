#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct state{
	int s[2][4];
	inline bool operator == (state v) const{
		for(int i=0;i<2;i++)
			for(int j=0;j<4;j++)
				if(v.s[i][j]!=this->s[i][j]) return false;
				
		return true;
	}
	inline bool operator <(state v) const{
		return true;
	}
};

state ini,fim;
typedef pair<ll,state> is;

ll S = 2;

inline ll hashC(int a[2][4]){
		ll t = 1,ans=0;
		int i,j;
		for(i=0;i<2;i++){
			for(j=0;j<4;j++){
				ans += a[i][j] * t;
				t *= 10;
			}
		}
	return ans;
}

inline int dijkstra(){

	state aux,at;
	ll d,ai;
	unordered_map<ll,ll> dist;
	priority_queue<is,vector<is>, greater<is> > pq;
	
	pq.push(make_pair(0,ini));
	dist[hashC(ini.s)] = 0;

	while(!pq.empty()){
		d  = pq.top().first;
		at = pq.top().second;
		pq.pop();

		if(at == fim)
			return d;
		
		for(int i=0;i<3;i++){
			aux = at;
			
			swap(aux.s[0][i],aux.s[0][i+1]);
			
			ai = hashC(aux.s);
			if(!dist.count(ai) or aux.s[0][i]+aux.s[0][i+1]+d < dist[ai]){
				pq.push(make_pair(d+aux.s[0][i]+aux.s[0][i+1],aux));
				dist[ai] = d+aux.s[0][i]+aux.s[0][i+1];
			}
			
			aux = at;
			
			swap(aux.s[1][i],aux.s[1][i+1]);
			
			ai = hashC(aux.s);
			if(!dist.count(ai) or aux.s[1][i]+aux.s[1][i+1]+d < dist[ai]){
				pq.push(make_pair(d+aux.s[1][i]+aux.s[1][i+1],aux));
				dist[ai] = d+aux.s[1][i]+aux.s[1][i+1];
			}
		}
		for(int i=0;i<4;i++){
			aux = at;
			
			swap(aux.s[0][i],aux.s[1][i]);
			
			ai = hashC(aux.s);
			if(!dist.count(ai) or aux.s[1][i]+aux.s[0][i]+d < dist[ai]){
				pq.push(make_pair(aux.s[1][i]+aux.s[0][i]+d,aux));
				dist[ai] = aux.s[1][i]+aux.s[0][i]+d;
			}
		}
	}
	return -1;
}



main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<4;j++){
			cin >> ini.s[i][j];
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<4;j++){
			cin >> fim.s[i][j];
		}
	}
	cout << dijkstra() << endl;
}
