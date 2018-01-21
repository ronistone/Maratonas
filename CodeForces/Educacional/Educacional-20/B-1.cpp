#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll A[200100];
ll dist[200100];
queue<pair<int,int> > q;
int n;
inline void bfs(){
	while(!q.empty()){
		ll d = q.front().first;
		int p = q.front().second;
		q.pop();
			
		if(p > 0 and dist[p-1] > d+1){
			q.push(make_pair(d+1,p-1));
			dist[p-1] = d+1;
		}
		if(p < n-1 and dist[p+1] > d+1){
			q.push(make_pair(d+1,p+1));
			dist[p+1] = d+1;
		}
	}
}


main(){

	while(cin >> n){
		for(int i=0;i<n;i++){
			dist[i] = 101010101010;
			cin >> A[i];
			if(A[i]==0){
				q.push(make_pair(0,i));
				dist[i] = 0;
			}
		}
		bfs();
		for(int i=0;i<n;i++){
			if(i!=0)
				cout << " ";
			cout << dist[i];
		}
		cout << endl;
	}
}
