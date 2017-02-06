#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;


main(){
	int i,j,k,n,a,b;
	vector<ii> valores;
	
	while(cin >> k){
		for(int x = k+1;x<=k*2;x++){
			int y = (k*x)/(x-k);
			if((k*x)%(x-k) == 0)
				valores.push_back(make_pair(y,x));
		}
		cout << valores.size() << endl;
		for(i=0;i<valores.size();i++){
			cout << "1/" << k << " = 1/" << valores[i].first << " + 1/" << valores[i].second << endl;
		}
		valores.clear();
	}
	
}
