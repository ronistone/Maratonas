#include <bits/stdc++.h>
using namespace std;


vector<int> tree[1010];


bool bfs(){
	queue<int> q;
	int v, child;
	q.push(1);
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		child = 0;
		for(int i=0;i<tree[v].size();i++){
			if(!tree[tree[v][i]].size())
				child++;
			q.push(tree[v][i]);
		}
		if(child < 3 and tree[v].size() > 0)
			return false;
		
	}
	return true;
}



main(){
	int n,a;
	cin >> n;
	
	
	for(int i=2;i<=n;i++){
		cin >> a;
		tree[a].push_back(i);
	}
	
	if(bfs()){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

}
