#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi st,A;

int n;
int left(int p){ return p << 1;}
int right(int p){ return (p << 1) + 1; }

int change (int lululu) {

	if (lululu == 0)
		return 0;
			
	else if (lululu < 0)
		return -1;
			
	else
		return 1;
}

void build(int p, int L, int R){
	if(L==R)
		st[p] = A[L];
	else{
		int nxt = p << 1;
		int mid = (L + R) >> 1;
		build(nxt, L, mid);
		build(nxt + 1, mid + 1, R);
		st[p] = st[nxt]*st[nxt + 1];
	}
}

void update (int p, int L, int R, int i, int value) {

	// no overlap
	if(L > i or R < i) return;
	
	// total overlap
	if(L == R and L == i) {
	
		st[p] = value;
		return;
	}

	int nxt = p << 1;
	int mid = (L + R) >> 1;
	update (nxt, L, mid, i, value);
	update (nxt + 1, mid + 1, R, i, value);
	
	st[p] = st[nxt] * st[nxt + 1];
}

int product(int p, int L, int R, int i, int j){

	// no overlap
	if(i>R || j<L) return 1;
	
	// total overlap
	if(L>=i && R<=j) return st[p];
	
	// partial overlap
	int nxt = p << 1;
	int mid = (L + R) >> 1;
	int p1 = product(nxt,L,mid,i,j);
	int p2 = product(nxt + 1,mid +1,R,i,j);
	
	return p1*p2;
}

main(){
	int i,j,k,f,t;
	char e;
	
	while(cin >> n >> k){
		A.resize (n << 1);
		st.resize (n << 2);
		A.assign(2*n,0);
		st.assign(4*n,0);
		
		for(i=0;i<n;i++){
			
			cin >> j;
			
			A[i] = change (j);
		}
		
		build(1,0,n-1);
		for(i=0;i<k;i++){
			cin.ignore();
			cin >> e >> f >> t;
			if(e=='C'){
				update (1, 0, n-1, f-1, change (t));
			}
			else if(e=='P'){
				j = product(1,0,n-1,f-1,t-1);
				
				if(j==0)
					cout << 0;
				else if(j<0)
					cout << '-';
				else
					cout << '+';
			}
		}
		cout << endl;
	}
}
