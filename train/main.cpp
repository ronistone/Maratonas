#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100000

typedef long long int ll;
typedef vector<ll> vi;

vi st, lazy;
string e,aux;

void build(int P, int L , int R){
	if(L == R){
		 st[P] = (e[L]=='1'?1:0);
	}else{
		int nxt = P << 1, mid = ((L+R)>>1);
		build(nxt, L, mid);
		build(nxt+1, mid+1, R);
		st[P] = st[nxt] + st[nxt+1];
	}
}

void reset(){
	int n = (e.size() << 2);
	st.resize(n);
	lazy.resize(n);
	st.assign(n, 0);
	lazy.assign(n, -1);
}

void createSt(){
	reset();
	build(1, 0, e.size()-1);
}

void doLazy(int P, int L, int R, int value){
	int nxt = P << 1;
	/*value = (value == -1)? lazy[P]:value;
	if(value!=-1){
		if(value != 2){
			st[P] = (R-L+1) * value;// (value==-1?st[P]:value);
		 //Inversão
		}else{
			st[P] = ((R-L+1) - st[P]);
		}
	}
	if(L!=R){
			lazy[nxt]   = value;
			lazy[nxt+1]  = value;
	}*/
	/*
	if(lazy[P]!=-1 or value != -1){
		if(lazy[P]!=2 and value != 2){
			st[P] = (R-L+1) * (value==-1? lazy[P]:value);
		}else{
			st[P] = ((R-L+1) - st[P]);
		}
	}
	if(L!=R){
		lazy[nxt]   = (value==-1? lazy[P]:value);
		lazy[nxt+1] = (value==-1? lazy[P]:value);
	}
	*/
	if(value != 2){
		st[P] = (R-L+1) * value;
	}else{
		st[P] = (R-L+1) - st[P];
	}
	if(R!=L){
		lazy[nxt] = value;
		lazy[nxt+1] = value;
	}
	lazy[P] = -1;
	
}

void doLazy(int P, int L, int R){
	int nxt = P << 1;
	if(lazy[P]!=-1){
		if(lazy[P]!=2){
			st[P] = (R-L+1) * lazy[P];
		}else{
			st[P] = ((R-L+1) - st[P]);
		}
	}
	if(L!=R){
		lazy[nxt]   = lazy[P];
		lazy[nxt+1] = lazy[P];
	}
	lazy[P] = -1;
	
}


void update(int P, int L, int R, int i, int j, int value){
		//doLazy(P, L, R, -1);
		doLazy(P,L,R);
		
		
		if(L > j or R < i or L > R) return;
		
		
		if(L >= i and R <= j){
			doLazy(P, L, R, value);
			return;
		}
		
		int nxt = P << 1;
		int mid = (L+R) >> 1;
		
		update(nxt, L, mid, i, j, value);
		update(nxt+1, mid+1, R, i, j , value);
		
		st[P] = st[nxt] + st[nxt+1];
}

void changeToBucc(int i, int j){
		update(1, 0, e.size()-1, i, j, 1);
}
void changeToBarb(int i, int j){
		update(1, 0, e.size()-1, i, j, 0);
}
void inverse(int i, int j){
		update(1, 0, e.size()-1, i, j, 2);
}

ll _query(int P, int L, int R, int i, int j){
	
	doLazy(P, L, R);
	if(L > j or R < i or L > R)	return 0;
	if(L >= i and R <= j) return st[P];
	
	int mid = (L+R) >> 1, nxt = P << 1;
	
	return _query(nxt, L, mid, i, j) + 
		   _query(nxt+1, mid+1, R, i, j);
	
}

ll query(int L, int R){
	return _query(1, 0, e.size()-1, L, R);
}

main(){
	int k,z,t, a, b, q = 0;
	
	
	cin >> k;
	
	for(int w = 1; w<=k; w++){
		cout << "Case " <<  w << ":" << endl;
		
		cin >> z;
		// Build
		e.clear();
		while(z--){
			cin >> t;
			cin >> aux;
			while(t--){
				e += aux;
			}
		}
		createSt();
		cin >> z;
		
		// Querys
		while(z--){
			cin >> aux >> a >> b;
			if(aux == "F"){
					changeToBucc(a,b);
			}
			else if(aux == "E"){
					changeToBarb(a,b);
			}
			else if(aux == "I"){
					inverse(a,b);
			}
			else if(aux == "S"){
					cout << "Q" << ++q << ": " << query(a,b) << endl;
			}
		}
	}

}
