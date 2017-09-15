#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> team,teamP,intraP;
int A[1010][1010];
int t[1010];

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,z,w,count = 0;
	string e;
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
	while(cin >> z and z){
		memset(t,0,sizeof t);
		for(int j=0;j<z;j++){
			cin >> n;
			for(int i=0;i<n;i++){
				cin >> A[j][i];
				team[A[j][i]] = j;
			}
		}
		int at = 1;
		cout << "Scenario #" << ++count << endl;
		cin.ignore();
		while(cin >> e and e!="STOP"){
			if(e=="ENQUEUE"){
				cin >> w;
				if(!teamP[team[w]]){
					teamP[team[w]] = at++;
				}
				t[team[w]]++;
				pq.push(make_pair(teamP[team[w]],make_pair(intraP[team[w]]++,w)));
			}
			else if(e=="DEQUEUE"){
				int x = pq.top().second.second;
				t[team[x]]--;
				if(!t[team[x]])
					teamP[team[x]] = 0;
				pq.pop();
				cout << x << endl;
			}
			cin.ignore();
			
		}
		while(!pq.empty()) pq.pop();
		team.clear();
		teamP.clear();
		intraP.clear();
		cout << endl;
	}

}
