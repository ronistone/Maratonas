#include <bits/stdc++.h>
using namespace std;


vector<int> graph[300];
bool visi[300];
int v, e;
int color[300];



int solve(int s){
	
	int zero = 0, one = 0;
	queue<int> q;
	q.push(s);
	color[s] = 0;
	visi[s] = true;
	
	while(!q.empty()){
	
		int at = q.front();
		q.pop();
		
		if(color[at]==0)
			zero++;
		else
			one++;
		
		for(int i=0;i<graph[at].size();i++){
			if( color[graph[at][i]] != 10 and color[graph[at][i]] == color[at] )
				return -1;
			else if( !visi[graph[at][i]] ){
				visi[graph[at][i]] = true;
				q.push(graph[at][i]);
				color[graph[at][i]] = color[at]==1?0:1;
			}
		}
		
	
	}
	if(zero==0)
		return one;
	else if(one == 0)
		return zero;
	
	return min(zero,one);

}

void clear(){
	memset(visi,false, sizeof visi);
	for(int i=0;i<v;i++){
		graph[i].clear();
		color[i] = 10;
	}

}


main(){
	int t, from, to,a,ans;
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> v >> e;
		clear();
		ans = 0;
		for(int j=0;j<e;j++){
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		bool fail = false;
		for(int j=0;j<v;j++){
			if(!visi[j]){
				a = solve(j);	
				if(a == -1){
					fail = true;
					break;
				}else{
					ans += a;
				}
			}
		}
		
		if(!fail)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
	
}
