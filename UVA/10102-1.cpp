#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long int ll;
typedef pair<ll,ll> ii;


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<ii> ini,fim;
	while(cin >> n){
		char matriz[n][n];
		for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
						cin >> matriz[i][j];
						if(matriz[i][j]=='3')
							fim.pb(mp(i,j));
						if(matriz[i][j]=='1')
							ini.pb(mp(i,j));
				}
		}
		ll ans = 0;
		for(int i=0;i<ini.size();i++){
			ll dist = 100000000;
				for(int j=0;j<fim.size();j++){
					ll temp = (abs(ini[i].F-fim[j].F)+abs(ini[i].S-fim[j].S));
					dist = min(dist,temp);
				}
			ans = max(dist,ans);
		}
		cout << ans << endl;
		ini.clear();
		fim.clear();
	}
		
}
