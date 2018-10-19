#include <bits/stdc++.h>
using namespace std;

map<string, int> nameToVertice;
map<int, string> verticeToName;

vector<int> graph[1000];
vector<int> ans;

int degree[1000];
int n,m;

void kahn(){

	priority_queue<int, vector<int>, greater<int> > q;
	
	for(int i=0;i<n;i++){
		if(degree[i] == 0 ){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int v = q.top();
		q.pop();
		
		for(int i=0;i<graph[v].size();i++){
			if(--degree[graph[v][i]] == 0){
				q.push(graph[v][i]);
			}
		}
		ans.push_back(v);
	}

}



main(){
	int v;
	string e, from , to;
	int c = 1;
	while(cin >> n){
		v = 0;
		ans.clear();
		for(int i=0;i<n;i++){
			cin >> e;
			
			degree[v] = 0;
			graph[v].clear();
			
			nameToVertice[e] = v;
			verticeToName[v++] = e;
		}
		
		cin >> m;
		
		for(int i=0;i<m;i++){
			cin >> from >> to;
			graph[nameToVertice[from]].push_back(nameToVertice[to]);
			degree[nameToVertice[to]]++;
		}
		
		kahn();
		
		
		cout << "Case #" << c++ << ": Dilbert should drink beverages in this order:";
		for(int i=0;i<ans.size();i++){
			cout << " " << verticeToName[ans[i]];
		}
		cout << "." << endl;
		cout << endl;
		
		nameToVertice.clear();
		verticeToName.clear();
	}
	

}
