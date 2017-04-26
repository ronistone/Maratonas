#include <bits/stdc++.h>
using namespace std;

int cont,t;
vector<string> P(300);

int diff(string a, string b){
	int ans = 0, i;
	for(i=0;i<a.size() and i<b.size();i++){
		if(a[i]!=b[i])
			ans++;
	}
	if(i<a.size() or i<b.size())
		return 10000000;
	return ans;
}


int bfs(string from, string to){
	
	queue<pair<int,string> > Q;
	bool visi[cont+5];
	memset(visi,false,sizeof visi);
	
	Q.push(make_pair(0,from));
	
	while(!Q.empty()){
		string at = Q.front().second;
		int dist = Q.front().first;
		Q.pop();
		 
		if(at==to)
			return dist;
			
		for(int i=0;i<cont;i++){
		
			if(diff(at,P[i])==1 and !visi[i]){
				Q.push(make_pair(dist+1,P[i]));
				visi[i] = true;
			}
			
		}
	}
	return -1;
}

main(){
	string e,from,to;
	stringstream ss;
	cin >> t;
	for(int k=0;k<t;k++){
		if(k!=0)
			cout << endl;
		cin.ignore();
		cont = 0;
		while(getline(cin,P[cont]) and P[cont++]!="*");
		while(getline(cin,e) and e.size()){
			ss << e;
			ss >> from;
			ss >> to;
			ss.clear();
			cout << e << " " << bfs(from,to) << endl;
		}
	}
}
