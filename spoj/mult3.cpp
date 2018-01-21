#include <bits/stdc++.h>
using namespace std;

int A[10000];
struct No{
	
	No *esq, *dir;
	int v;
	
	No(){
		esq = dir = NULL;
		v = 0;
	}
	void build(int _L, int _R){
		
		if(_L == _R) v = A[_L]%3==0?1:0;
		else{
			int mid = (_L + _R) >> 1;
			
			if(!esq) esq = new No();
			if(!dir) dir = new No();
			esq -> build(_L,mid);
			dir -> build(mid+1,_R);
			
			v = esq -> v + dir -> v;
		}
	}
	void update(int _L, int _R, int i, int _v){
		
		if(i > _R or i < _L) return;
		
		if(i == _L and i == _R){
			v = _v%3? 1:0;
			return;
		}
		int mid = (_L + _R) >> 1;
		esq -> update(_L,mid, i, _v);
		dir -> update(mid+1, _R, i, _v);
	}
	int query(int _L, int _R, int i, int j){
		
		if(i > _R or j < _L) return 0;
		if(_L >= i and _R <= j) return v;
		
		int mid = (_L + _R) >> 1;
		return esq -> query(_L, mid, i, j) + dir -> query(mid+1, _R, i, j);
	}
};

main(){
	
	int n,q,a,b;
	char o;
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> A[i];
	}
	No* seg = new No();
	
	seg -> build(1,n);
	
	cin >> q;
	
	for(int i=0;i<q;i++){
		cin.ignore();
		cin >> o >> a >> b;
		if(o == 'U')
			seg -> update(1,n,a,b);
		else if(o == 'Q')
			cout << seg -> query(1,n,a,b) << endl; 
	}
}
