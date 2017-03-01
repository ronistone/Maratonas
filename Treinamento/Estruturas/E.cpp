#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct no{
	ll pre, suf, mid;
	ll sum;
	no(ll p_,ll s_,ll sum_,ll mid_): pre(p_),suf(s_),sum(sum_),mid(mid_){}
	no(){}
	void set(ll p,ll s,ll su,ll m){ pre = p; suf = su; sum = s; mid = m; }
	ll getPre(no a){ return max(sum+a.pre,pre); }
	ll getSuf(no a){ return max(suf,sum+a.suf); }
}V;
inline bool operator ==(const V &a, const V &b){
	return a.pre==b.pre and a.suf==b.suf and a.sum==b.sum and a.mid==b.mid;
}
V merge(V a, V b){
	
	V ans;
	
	ans.sum = a.sum+b.sum;
	ans.pre = max(a.pre,a.sum+b.pre);
	ans.suf = max(b.suf,b.sum+a.suf);
	ans.mid = max(a.mid,max(b.mid,a.suf+b.pre));	
	
	return ans;
}

typedef vector<V> seg;
typedef vector<ll> vi;

seg st;
ll A[50100];
int n,m;

void build(ll P, ll L, ll R){
	if(L==R)
		st[P].set(A[L],A[L],A[L],A[L]);
	else{
		ll nxt = P << 1;
		ll mid = (L+R) >> 1;
		
		build(nxt,L,mid);
		build(nxt+1,mid+1,R);
		st[P] = merge(st[nxt],st[nxt+1]);
		//st[P].set(st[nxt].getPre(st[nxt+1]),st[nxt].sum+st[nxt+1].sum,st[nxt+1].getSuf(st[nxt]),st[nxt].suf+st[nxt+1].pre);
	}
}
void update(ll P, ll L, ll R, ll X, ll value){
		
	if(L>X or R < X) return;
	if(L==X and R==X){ st[P].set(value,value,value,value); return;}
	
	ll nxt = P << 1;
	ll mid = (L+R) >> 1;
	
	update(nxt,L,mid,X,value);
	update(nxt+1,mid+1,R,X,value);
	st[P] = merge(st[nxt],st[nxt+1]);
	//st[P].set( st[nxt].getPre(st[nxt+1]) , st[nxt].sum+st[nxt+1].sum , st[nxt+1].getSuf(st[nxt]), st[nxt].suf+st[nxt+1].pre);
}
V query(ll P, ll L, ll R, ll i, ll j){
	V t = V(-10e14,-10e14,-10e14,-10e14);
	if(L>j or R<i) return t;
	if(L>=i and R<=j) return st[P];
	
	ll nxt = P << 1;
	ll mid = (L+R) >> 1;
	V q = query(nxt,L,mid,i,j);
	V q1 = query(nxt+1,mid+1,R,i,j);
	if(q==t) return q1;
	if(q1==t) return q;
	return merge(q,q1);
	return V( q.getPre(q1) , q.sum+q1.sum , q1.getSuf(q), q.suf+q1.pre);
	
}

main(){
	int x,y,op;
	
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> A[i];
		}
		st.resize(n << 2);
		st.assign(n << 2, V(0,0,0,0));
		build(1,0,n-1);
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> op >> x >> y;
			if(op){
				V q = query(1,0,n-1,x-1,y-1);
				cout << max(q.pre,max(q.sum,max(q.mid,q.suf))) << endl;
			}
			else if(!op){
				update(1,0,n-1,x-1,y);
			}
		}
	}
}
