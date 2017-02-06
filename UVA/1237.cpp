#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back


typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<string,ii> sii;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,j,k,n,z,qu,q;
	vector<sii> car;
	cin >> z;
	
	for(i=0;i<z;i++){
		cin >> n;
		for(j=0;j<n;j++){
			car.pb(mp("",mp(0,0)));
			cin >> car[j].F >> car[j].S.F >> car[j].S.S;
		}
		cin >> qu;
		for(j=0;j<qu;j++){
			string ans = "UNDETERMINED";
			cin >> q;
			for(k=0;k<car.size();k++){
//				cout << "A: " << ans << endl;
				if(ans == "UNDETERMINED" and car[k].S.F<=q and car[k].S.S >=q)
					ans = car[k].F;
				else if(ans != "UNDETERMINED" and car[k].S.F<=q and car[k].S.S >=q){
					ans = "UNDETERMINED";
					break;
				}
			}
			cout << ans << endl;
		}
			car.clear();
			if(i!=z-1)
				cout << endl;
	}
}
