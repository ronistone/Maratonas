#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long int ll;

int parent[400100],n,m;
vector<pair<ll,pair<int,int> > > A;

inline int findset(int x){
	if(parent[x]!=x)
		parent[x] = findset(parent[x]);
	return parent[x];
}
inline void UNION(int x, int y){
	parent[x] = parent[y];
}
ll kruskal(){
	sort(A.begin(),A.end());
	int pu,pv;
	ll ans = 0;
	for(int i=0;i<A.size();i++){
		pu = findset(A[i].S.F);
		pv = findset(A[i].S.S);
		if(pu!=pv){
			ans += A[i].F;
			UNION(pv,pu);
		}
	}
	return ans;
}




main(){
	int from,to,w;
	while(cin >> n >> m and m and n){
		for(int i=0;i<=n;i++)
			parent[i] = i;
		for(int i=0;i<m;i++){
			cin >> from >> to >> w;
			A.pb(mp(w,mp(from,to)));
		}
		cout << kruskal() << endl;
		A.clear();
	}
}
