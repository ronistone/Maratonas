#include <bits/stdc++.h>
using namespace std;

struct no{
	int left, center, right;
};

vector<no> arvL(10010),arvR(10010);



int bfs(vector<no> arv){
		
	queue<pair<int,int> > q;
	
	q.push(make_pair(1,1));
	int ans = 0;
	while(!q.empty()){
		int d = q.front().first;
		int v = q.front().second;
		q.pop();
		
		ans = max(ans,d);
		
		if(arv[v].left){
			q.push(make_pair(1,arv[v].left));
		}
		if(arv[v].center){
			q.push(make_pair(d+1,arv[v].center));
		}
		if(arv[v].right){
			q.push(make_pair(1,arv[v].right));
		}
			
	}
	return ans;
}


main(){
	int n,m,p,left,center,right;
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p >> left >> center;
		if(left){
			arvL[p].left = left;
		}
		else
		{
			arvL[p].left = 0;
		}
		
		if(center){
			arvL[p].center = center;
		}
		else
		{
			arvL[p].center = 0;
		}
		
		arvL[p].right = 0;
	}
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> p >> center >> right;
		if(right){
			arvR[p].right = right;
		}
		else{
			arvR[p].right = 0;
		}
		
		if(center){
			arvR[p].center = center;
		}
		else{
			arvR[p].center = 0;
		}
		
		arvR[p].left = 0;
	}
	cout << n+m - min(bfs(arvL),bfs(arvR)) << endl;
	
}
