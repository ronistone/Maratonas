#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define INF -1000000
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<iii> viii;
typedef vector<ll> vi;

viii st;
vi A;
int n,m;

ll maior(iii a){ return max(a.F,max(a.S.F,a.S.S));}
void build(int P, int L, int R){
	if(L==R){
		st[P] = mp(A[L],mp(A[L],A[L]));
	}
	else{
		int nxt = P << 1;
		int mid = (L+R) >> 1;
		build(nxt,L,mid);
		build(nxt+1,mid+1,R);
		ll m1 = maior(st[nxt]);
		ll m2 = maior(st[nxt+1]);
		st[P] = mp(m1,mp(m1+m2,m2));
	}
}
void update(int P, int L, int R, int i, int value){

	// total overlap
	if(L==R and L==i){
		st[P] = mp(value,mp(value,value));
		return;
	}	
	// no overlap
	if(L>i or R<i) return;
	
	// partial overlap
	int nxt = P << 1;
	int mid = (L+R) >> 1;
	update(nxt,L,mid,i,value);
	update(nxt+1,mid+1,R,i,value);
	ll m1 = maior(st[nxt]);
	ll m2 = maior(st[nxt+1]);
	st[P] = mp(m1,mp(m1+m2,m2));		
}
iii query(int P, int L, int R, int i, int j){
	if(R<i or L>j) return mp(INF,mp(INF,INF));
	if(L>=i and R<=j) return st[P];
	
	int nxt = n << 1;
	int mid = (L+R) >> 1;
	iii q1 = query(nxt,L,mid,i,j);
	iii q2 = query(nxt+1,mid+1,R,i,j);
	if(q1.F==INF and q1.S.F==INF and q1.S.S==INF) return q2;
	if(q2.F==INF and q2.S.F==INF and q2.S.S==INF) return q1;
	ll m1 = maior(q1);
	ll m2 = maior(q2);
	if(max(m1,m2)==m1)
		return q1;
	else
		return q2;	
}

main(){
	int i,j,k,o,a,b;
	
	while(cin >> n){
		st.resize(n << 2);
		A.resize(n << 1);
		st.assign(n << 2,mp(0,mp(0,0)));
		A.assign(n << 1,0);
		for(i=0;i<n;i++){
			cin >> A[i];	
		}
		build(1,0,n-1);
		cin >> m;
		
		for(i=0;i<m;i++){
			cin >> o >> a >> b;
			if(o==0)
				update(1,0,n-1,a-1,b);
			else{
				iii aux = query(1,0,n-1,a-1,b-1);
				cout << max(aux.F,max(aux.S.F,aux.S.S)) << endl;
			}
		}
	}
}
