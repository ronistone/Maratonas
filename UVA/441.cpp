#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
//#define S second

typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;



main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,aux;
	vi S;
	bool first = true;
	while(cin >> n and n){
		if(!first)
			cout << endl;
		for(int i=0;i<n;i++){
			cin >> aux;
			S.pb(aux);
		}
		for(int i=0;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int k=j+1;k<n-3;k++){
					for(int l=k+1;l<n-2;l++){
						for(int z=l+1;z<n-1;z++){
							for(int x=z+1;x<n;x++){
								cout << S[i] << " " << S[j] << " " << S[k] << " " << S[l] << " " << S[z] << " " << S[x] << endl;
							}
						}
					}
				}
			}
		}
		S.clear();
		first = false;
	}
	


}
