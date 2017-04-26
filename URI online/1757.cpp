#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
unordered_map<int,unordered_map<int,bool> > show;

typedef long long int ll;
int n,m;

ll bfs(int ini){
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
	bool visi[n];
	ll d = -1;
	memset(visi,false,sizeof visi);
	pq.push(mp(0,ini));
	visi[0] = true;
	int vi = 0;
	while(!pq.empty()){
		d = pq.top().F;
		//cout << "dist " << d << endl;
		int v = pq.top().S;
		pq.pop();
		for(int i=0;i<n;i++){
			if(!visi[i]){
				pq.push(mp(d+(show[v][i]?1:0),i));
				visi[i] = true;
				vi++;
			}
		}
	}
	//cout << vi << endl;
	if(vi==n-1)
		return d;
	else
		return INT_MAX;
}



main(){
	
	int z,from,to;
	
	cin >> z;
	
	
	for(int k=0;k<z;k++){
		
		cin >> n >> m;
		
		
		for(int i=0;i<m;i++){
			cin >> from >> to;
			show[from][to] = true;
			show[to][from] = true;
		}
		ll ans = 1010101010101010;
		for(int i=0;i<n;i++)
			ans = min(ans,bfs(i));
			
		cout << ans << endl;
		show.clear();
	}

}
