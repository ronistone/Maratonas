#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back

int parent[600];
vector<pair<double,pair<int,int> > > A;
pair<int,int> P[600];

double calc(int i,int j){
	return sqrt(((P[i].F - P[j].F)*(P[i].F - P[j].F)) + ((P[i].S - P[j].S)*(P[i].S - P[j].S)));
}
int findset(int x){
	if(x!=parent[x])
		parent[x] = findset(parent[x]);
	return parent[x];
}
void UNION(int x,int y){
	parent[x] = parent[y];
}
double kruskal(){
	double ans = 0;
	int pu,pv;
	sort(A.begin(),A.end());
	for(int i=0;i<A.size();i++){
		pu = findset(A[i].S.F);
		pv = findset(A[i].S.S);
		if(pu!=pv){
			ans += A[i].F;
			UNION(pu,pv);
		}
	}
	return ans;
}



main(){
	int n,x,y;
	
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> x >> y;
			P.pb(mp(x,y));
			parent[i] = i;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				A.pb(mp(calc(i,j),mp(i,j)));
			}
		}
		cout << fixed << setprecision(2) << kruskal() << endl;
	
	}
	

}
