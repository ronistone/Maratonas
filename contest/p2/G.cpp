#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;

main(){
	ll n,m, from ,to;
	
	while(cin >> n >> m and n){
		vector<ll> G(n,0);
		for(int i=0;i<m;i++){
			cin >> from >> to;
			G[from]++;
			G[to]++;
		}
		bool achou = false;
		for(int i=0;i<n;i++){
			if(G[i]> 2)
				achou = true;
		}
		if(achou)
			cout << "SIM" << endl;
		else
			cout << "NAO" << endl;
			
	}
	
}
