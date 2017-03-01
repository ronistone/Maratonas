#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

vi lazy,st;
string A;

void build(ll P, ll L, ll



main(){
	int z,n,q,from,to,v;
	string E;
	cin >> z;
	
	for(int k=0;k<z;k++){
		
		cin >> q;
		A = "";
		for(int i=0;i<n;i++){
			cin >> n >> E;
			for(int j=0;j<n;j++)
				A += E;
		}
		cin >> q;
		n = A.size();
		
		st.resize(n << 2);
		lazy.resize(n << 2);
		st.assign(n << 2, 0);
		lazy.assign(n << 2, 0);
		
		build(1,0,n-1);
		cout << "Case " << k+1 << ":\n";
		ll cont = 1;
		for(int i=0;i<q;i++){
			cin >> E >> from >> to;
			if(E=="F"){
				update(1,0,n-1,from,to,1);
			}
			else if(E=="E"){
				update(1,0,n-1,from,to,0);
			}
			else if(E=="I"){
				update(1,0,n-1,from,to,-1);
			}
			else if(E=="S"){
				cout << "Q" << cont++ << ": " << query(1,0,n-1,from,to) << endl;
			}
		}
		
	}
		
}
