#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;
typedef vector<iii> viii;

viii st;
vi lazy;
int n,m;

void build(int P, int L, int R){
	if(L==R){
		st[P] = mp(1,mp(0,0));
	}
	else{
		int nxt = P << 1;
		int mid = (L+R) >> 1;
		build(nxt,L,mid);
		build(nxt+1,mid+1,R);
		st[P] = mp(st[nxt].F + st[nxt+1].F,mp(st[nxt].S.F + st[nxt+1].S.F, st[nxt].S.S + st[nxt+1].S.S));
	}
}
void mover(int P,int v){
	for(int i=0;i<v;i++){
		ll aux;
		aux = st[P].S.F; 
		st[P].S.F = st[P].F; // Move primeiro para o segundo
		st[P].F = st[P].S.S; // Move terceiro para o primeiro
		st[P].S.S = aux;  // Move segundo para o terceiro
	}
}

void update(int P, int L, int R, int i, int j){
	int nxt = P << 1;
	if(lazy[P]!=0){
		mover(P,lazy[P]%3);
		
		if(L!=R){
			lazy[nxt] += lazy[P];
			lazy[nxt+1] += lazy[P];
		}
		lazy[P] = 0;
	}
	if(R<i or L>j) return;
	
	if(L>=i and R<=j){
		mover(P,1);
		if(L!=R){
			lazy[nxt]++;
			lazy[nxt+1]++;
		}
		return;
	}
	int mid	= (L+R) >> 1;
	update(nxt,L,mid,i,j);
	update(nxt+1,mid+1,R,i,j);
	st[P] = mp(st[nxt].F + st[nxt+1].F,mp(st[nxt].S.F + st[nxt+1].S.F, st[nxt].S.S + st[nxt+1].S.S));
}

iii query(int P, int L, int R, int i,int j){
	int nxt = P << 1;
	if(lazy[P]!=0){
		mover(P,lazy[P]%3);
		
		if(L!=R){
			lazy[nxt] += lazy[P];
			lazy[nxt+1] += lazy[P];
		}
		lazy[P] = 0;
	}
	// no overlap
	if(R<i or L>j) return mp(0,mp(0,0));
	
	// total overlap
	if(L>=i and R<=j) return st[P];
	
	// parcial overlap
	int mid = (L+R) >> 1;
	iii l1 = query(nxt,L,mid,i,j);
	iii l2 = query(nxt+1,mid+1,R,i,j);
	
	if(l2.F==0 and l2.S.F==0 and l2.S.S==0) return l1;
	if(l1.F==0 and l1.S.F==0 and l1.S.S==0) return l2;
	
	return mp(l1.F + l2.F,mp(l1.S.F + l2.S.F, l1.S.S + l2.S.S));
}


main(){
	int i,j,k,a,b;
	char o;
	
	while(cin >> n >> m){
		st.resize(n << 2);
		lazy.resize(n << 2);
		lazy.assign(n << 2, 0);
		build(1,0,n-1);
		for(i=0;i<m;i++){
			cin.ignore();
			cin >> o >> a >> b;
			if(o=='C'){
				iii aux = query(1,0,n-1,a-1,b-1);
				cout << aux.F << " " << aux.S.F << " " << aux.S.S << endl;;
			}
			else{
				update(1,0,n-1,a-1,b-1);
			}
		}
		cout << endl;
	}
}





