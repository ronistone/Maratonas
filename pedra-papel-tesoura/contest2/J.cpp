#include <bits/stdc++.h>
using namespace std;

const int N = 102;

int ant[N], prox[N], ord[N], vis[N], n, V[N], SOLVE=1, uh;
vector<int> hit[N], start[N];


void dfs_hit(int U, int u) {
	vis[u] = 1; 
	hit[U].push_back(u);
	
	if(prox[u] != -1 && !vis[prox[u]]) dfs_hit(U, prox[u]);
	if(ant[u] != -1 && !vis[ant[u]]) dfs_hit(U, ant[u]);
}

void dfs_start(int U, int u) {
	vis[u] = 1; 
	start[U].push_back(u);
	
	if(prox[u] != -1 && !vis[prox[u]]) dfs_start(U, prox[u]);
}

void dfs_hit_solve(int u, int pos) {
	V[u] = 1; 
	ord[pos] = u;
	if(pos-1 >=0 && ant[u] != -1 && !V[ant[u]]) dfs_hit_solve(ant[u], pos-1);
	if(pos+1 < n && prox[u] != -1 && !V[prox[u]]) dfs_hit_solve(prox[u], pos+1);
}

void solve() {
	
	for(int i=0; i<n; i++) {
		if(ord[i] != -1 && V[ord[i]] != 1){
			 dfs_hit_solve(ord[i], i);
		 }
	}
}

bool check(int u) {
	int h = hit[u].size(), c=0;
	
	for(int i=0; i<(int)hit[i].size(); i++) {
		if(h == start[hit[u][i]].size()) {uh = hit[u][i]; c++;}
	}
	if(c>1) return false;
	return true;
}

int main()
{
	cin >> n;
	
	for(int i=0; i<n; i++) prox[i] = ant[i] = -1;
	for(int i=0; i<n; i++) V[i] = 0;
	for(int i=0; i<n; i++) {
		cin >> prox[i]; prox[i]--;
		ant[prox[i]] = i;
	}
	for(int i=0; i<n; i++) {
		cin >> ord[i];
		ord[i]--;
		if(ord[i] == -1) continue;
		V[ord[i]] = 2;
	}
	
	for(int i=0; i<n; i++) {
		memset(vis, 0, sizeof vis);
		dfs_hit(i,i);
		
		memset(vis, 0, sizeof vis);
		dfs_start(i,i);
	}
	
	solve();
	
	memset(vis, 0, sizeof vis);
	
	for(int i=0; i<n; i++) {
		if(ord[i] == -1) {
			puts("-1");
			return 0;
		}
	}
	for(int i=0; i<n; i++) {
		if(i) printf(" ");
		printf("%d", 1+ord[i]);
	}
	puts("");
}
