#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second

vector<pair<int,int> > A;
int parent[100100];
int n,m;

inline int findset(int x){
	if(x!=parent[x])
		parent[x] = findset(parent[x]);
	return parent[x];
}
inline void UNION(int x,int y){
	parent[x] = parent[y];
}

bool kruskal(){
	
	int pu,pv;
	for(int i=0;i<A.size();i++){
		pu = findset(A[i].F);
		pv = findset(A[i].S);
		if(pu!=pv)
			UNION(pv,pu);
		else
			return false;
	}
	return true;
}


main(){
	int from,to;
	while(cin >> n >> m){
		for(int i=0;i<m;i++){
			cin >> from >> to; from--; to--;
			A.pb(mp(from,to));
		}
		for(int i=0;i<n;i++)
			parent[i] = i;
		if(kruskal())
			cout << "Seguro" << endl;
		else
			cout << "Inseguro" << endl;
		A.clear();
	}

}
