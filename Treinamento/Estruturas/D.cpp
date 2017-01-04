#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

string A;
vi st,lazy;
int n,m;

void build(int p,int L,int R){
	if(L==R)
		st[p] = (int) A[L] - 48;
		
	else{
		int nxt = p << 1;
		int mid = (L+R) >> 1;
		build(nxt,L,mid);
		build(nxt+1,mid+1,R);
		st[p] = st[nxt]+st[nxt+1];
	}
}
void update(int p,int L,int R,int i,int j,int value){
	int nxt = p << 1;
	
	if(lazy[p]!=-2){
		if(L!=R){
			if(lazy[p]==-1){
				st[p] = (R-L+1) - st[p];
				lazy[nxt] = lazy[nxt]==-2 ? -1:1 - lazy[nxt];
				lazy[nxt+1] = lazy[nxt+1]==-2 ? -1:1 - lazy[nxt+1];
			}
			else{
				ll aux = (R-L+1)*lazy[p];
				st[p] = lazy[p]==0? 0:aux;
				lazy[nxt] = lazy[p];
				lazy[nxt+1] =lazy[p];
			}
		}
		else{
			st[p] = lazy[p]==-1 ? (R-L+1)-st[p]:lazy[p];
		}
		lazy[p] = -2;
	}
	
	if( L > j or R < i) return;
	
	if(L>=i and R<=j){
		if(L!=R){
			if(value==-1){
				st[p] = (R-L+1) - st[p];
				lazy[nxt] = lazy[nxt]==-2 ? -1:1 - lazy[nxt];
				lazy[nxt+1] = lazy[nxt+1]==-2 ? -1:1 - lazy[nxt+1];
			}
			else{
				ll aux = (R-L+1)*value;
				st[p] = value==0? 0:aux;
				lazy[nxt] = value;
				lazy[nxt+1] = value;
			}
		}
		else{
			st[p] = value==-1? (R-L+1)-st[p]:value;
		}
		return;
	}
	int mid = (L+R) >> 1;
	
	update(nxt,L,mid,i,j,value);
	update(nxt+1,mid+1,R,i,j,value);
	
	st[p] = st[nxt]+st[nxt+1];
}
ll query(int p,int L,int R,int i,int j){
	int nxt = p << 1;
	
	if(lazy[p]!=-2){
		if(L!=R){
			if(lazy[p]==-1){
				st[p] = (R-L+1) - st[p];
				lazy[nxt] = lazy[nxt]==-2 ? -1:1 - lazy[nxt];
				lazy[nxt+1] = lazy[nxt]==-2 ? -1:1 - lazy[nxt];
			}
			else{
				ll aux = (R-L+1)*lazy[p];
				st[p] = lazy[p]==0? 0:aux;
				lazy[nxt] = lazy[p];
				lazy[nxt+1] =lazy[p];
			}
		}
		else{
			st[p] = lazy[p]==-1? (R-L+1) - st[p]:lazy[p];
		}
		lazy[p] = -2;
	}
	
	if(R < i || L > j) return 0;
	
	if(L>=i and R<=j) return st[p];
	
	int mid = (R+L) >> 1;
	
	return query(nxt,L,mid,i,j) + query(nxt+1,mid+1,R,i,j);
		
}

main(){
	string e;
	char o;
	int i,j,k,z,r,q,a,b;
	
	cin >> z;
	
	for(k=0;k<z;k++){
		cout << "Case " << k+1 << ":\n";
		cin >> m;
		for(i=0;i<m;i++){
			cin >> r;
			cin.ignore();
			getline(cin,e);
			for(j=0;j<r;j++){
				A += e;
			}
		}
		n = A.size();
		st.resize(n << 2);
		lazy.resize(n << 2);
		st.assign(n << 2,0);
		lazy.assign(n << 2,-2);
		build(1,0,n-1);
		cin >> q;
		int cont = 0;
		for(i=0;i<q;i++){
			cin.ignore();
			cin >> o >> a >> b;
			if(o=='F')
				update(1,0,n-1,a,b,1);
			else if(o=='E')
				update(1,0,n-1,a,b,0);
			else if(o=='I')
				update(1,0,n-1,a,b,-1);
			else{
				cont++;
				cout << "Q" << cont << ": " << query(1,0,n-1,a,b) << endl;
			}
		}
		A.clear();
	}
}
