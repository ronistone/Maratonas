#include <bits/stdc++.h>
using namespace std;

main(){
	int n,m,i,j,k,v,aux;
	vector<int> vi;
	map<pair<int,int>,int> mapa;
	map<int,int> c;
	
	while(cin >> n >> m){
		for(i=0;i<n;i++){
			cin >> aux;
			c[aux]++;
			mapa[pair<int,int>(c[aux],aux)] = i+1;
		}
		for(i=0;i<m;i++){
			cin >> k >> v;
			if(mapa.count(pair<int,int>(k,v)))
				cout << mapa[pair<int,int>(k,v)] << endl;
			else{
				cout << 0 << endl;
			}
		}
		mapa.clear();
		c.clear();
	}
}	
