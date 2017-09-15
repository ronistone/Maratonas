#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long int ll;

vector<pair<ll,pair<int,int> > > st(200005 << 2);
vector<pair<ll,pair<int,int> > >  lazy(200005 << 2);
ll A[200005];

void build(int P, int L,int R){
	if(L==R) st[P] = {A[L],{A[L]==7?1:0,A[L]==13?1:0}};
	else{
		int nxt = P << 1;
		int mid = (L+R) >> 1;
		build(nxt,L,mid);
		build(nxt+1,mid,R);
		st[P].F = st[nxt].F+st[nxt+1].F;
		st[P].S.F = st[nxt].F+st[nxt+1].S.F;
		st[P].S.S = st[nxt].F+st[nxt+1].S.S;
	}
}
void update(int P, int L, int R, int i,int j,int value,int ind){
	int nxt = P<<1;
	
	if(lazy[P].S.S!=0 or lazy[P].F!=0 or lazy[P].S.F!=0){
		if(lazy[P].F!=0){
			st[P].F = (R-L+1)*lazy[P].F;
			if(lazy[P].F!=7){
				st[P].S.F = 0;
				lazy[P].S.F = 0;
			}
			if(lazy[P].F!=13){
				st[P].S.S = 0;
				lazy[P].S.S = 0;
			}
		}
		else if(lazy[P].S.S!=0){ // change 13 for 7
			st[P].F += ((lazy[P].S.S-13)*st[P].S.S);
			st[P].S.F += st[P].S.S;
			st[P].S.S = 0;
		}
		else if(lazy[P].S.F!=0){ // change 7 for 13
			st[P].F += ((lazy[P].S.F-7)*st[P].S.S);
			st[P].S.S += st[P].S.F;
			st[P].S.F = 0;
		}
		if(R!=L){
			lazy[P << 1] = lazy[P];
			lazy[(P << 1)+1] = lazy[P];
		}
		lazy[P].S.S = 0;
		lazy[P].S.F = 0;
		lazy[P].F = 0;
	}
	
	if(L > j or R < i) return;
	if(L>=i and R <=j){
		if(id==-1){ // change 13 for value
			st[P].F += ((value-13)*st[P].S.S);
			if(value==7)
				st[P].S.F += st[P].S.S;
			if(value!=13)
				st[P].S.S = 0;
		}
		else if(ind==-2){ // change 7 for value
			st[P].F += ((value-7)*st[P].S.F);
			if(value==13)
				st[P].S.S += st[P].S.F;
			if(value!=7)
				st[P].S.F = 0;
		}
		else{
			st[P].F = (R-L+1)*value;
		}
		if(L!=R){
			if(ind==-1){ 
				lazy[nxt].S.S = value;
				lazy[nxt+1].S.S = value;
			}
			else{
				lazy[nxt].F = value;
				lazy[nxt+1].F = value;
			}
		}
		return;
	}
	
	int mid = (L+R) >> 1;
	update(nxt,L,mid,i,j,value,ind);
	update(nxt+1,mid,R,i,j,value,ind);
	st[P].F = st[nxt].F + st[nxt+1].F;
	st[P].F = st[nxt].S.F + st[nxt+1].S.F;
	st[P].F = st[nxt].S.S + st[nxt+1].S.S;
}
ll query(int P, int L, int R, int i, int j){
	
	

}


main(){
	
	int n,from,to,x,value,q,m;
	pair<ll,pair<int,int> > aux,aux1;
	aux = aux1 = {0,{0,0}};
	while(cin >> n){
		fill(st.begin(),st.begin()+(n<<2),aux1);
		fill(lazy.begin(),lazy.begin()+(n<<2),aux);
		for(int i=0;i<n;i++){
			cin >> A[i];
		}
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> q;
			build(1,0,n-1);
			if(q==1){
				cin >> from >> to;
				update(1,0,n-1,from,from,to,0);
			}
			else if(q==2){
				cin >> from >> to >> x >> value;
				if(x == 13)
					update(1,0,n-1,from,to,value,-1);
				else
					update(1,0,n-1,from,to,value,-2);
			}
			else if(q==3){
			
			}
		}
	}

}
