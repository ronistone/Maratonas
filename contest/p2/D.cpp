#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

vi st(10e6,0);


void update(ll P,ll L,ll R,ll X,ll V){
	if(L>X or R<X) return;
	
	if(L==X and R==X){
		if(not(V==-1 and st[P]==0))
			st[P] += V;
		return;
	}
	
	ll nxt = P << 1;
	ll mid = (L+R) >> 1;
	
	update(nxt,L,mid,X,V);
	update(nxt+1,mid+1,R,X,V);

	st[P] = st[nxt]+st[nxt+1];
}
ll query(ll P,ll L,ll R,ll i,ll j){
	
	if(L>j or R<i) return 0;
	if(L>=i and R<=j) return st[P];
	
	ll nxt = P << 1;
	ll mid = (L+R) >> 1;
	
	return query(nxt,L,mid,i,j) + query(nxt+1,mid+1,R,i,j);
}


main(){
	ll n;
	ll from, to,x;
	string E;
	
	cin >> n;
	
	for(ll k =0;k<n;k++){
		cin >> E;
		
		if(E=="+"){
			cin >> x;
			update(1,0,10e5,x-1,1);
		}
		else if(E=="-"){
			cin >> x;
			update(1,0,10e5,x-1,-1);
		}
		else{
			cin >> from >> to;
			
			cout << query(1,0,10e5,from-1,to-1) << endl;
		}
	}

}
