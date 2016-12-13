#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

main(){
	int t,f,saida=0,tf=0;
	int d = 0;
	priority_queue<ii,vii,greater<ii> > pq;
	while(cin >> t >> f){
		pq.push(make_pair(t,f));
		tf+= f;
		if(d==0){
			d = pq.top().first;
			tf-= pq.top().second;
			pq.pop();
		}
		saida+=tf;
		d--;
	}
	while(!pq.empty()){
		if(d==0){
			d = pq.top().first;
			tf-= pq.top().second;
			pq.pop();
		}
		saida+=tf;
		d--;
	}
	cout << saida << endl;
}
