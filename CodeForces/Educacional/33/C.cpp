#include <bits/stdc++.h>
using namespace std;
#define N 100010

typedef long long int ll;

int A[N];
vector<vector<int> > Grafo(N);
bool visi[N];

inline ll dfs(int i){
	visi[i] = true;
	ll ans = A[i];
	for(int j=0;j<Grafo[i].size();j++){
		if(!visi[Grafo[i][j]]){
			ans = min(ans,dfs(Grafo[i][j]));
		}
	}
	return ans;
}


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,from,to;
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<m;i++){
		cin >> from >> to; from--; to--;
		Grafo[from].push_back(to);
		Grafo[to].push_back(from);
	}
	
	ll ans = 0;
	memset(visi,false,sizeof visi);
	for(int i=0;i<n;i++){
		if(!visi[i]){
			ans += dfs(i);
		}
	}
	cout << ans << endl;
}
