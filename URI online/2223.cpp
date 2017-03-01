#include <bits/stdc++.h>
using namespace std;
#define UE printf("\n\nAQUI\n\n");
typedef long long int ll;

typedef struct no{
	int op;
	int from,to,num;
	int k,v;
	no(int op_,int from_,int to_,int k_,int num_): op(op_),from(from_),to(to_),k(k_),num(num_) {}
	no(int op_,int from_,int v_): op(op_),from(from_),v(v_) {}
}Op;

inline bool operator>(const Op &a ,const Op &b){
	return a.k > b.k;
}
inline bool operator<(const Op &a, const Op &b){
	return a.k < b.k;
}
inline bool operator==(const Op &a, const Op &b){
	return a.k == b.k;
}

int n;
ll BIT[101000],A[101000];
priority_queue<Op,vector<Op>, greater<Op> > pq1;
int t,aux,q,from,to,k,op,v,cont,z;
queue<Op> pq2;

inline void update(ll value,int index){
	for(;index <= n;index += index & (-index))
		BIT[index] += value;
}
inline ll query(int index){
	ll ans = 0;
	for(;index > 0;index -= index & (-index))
		ans += BIT[index];
		
	return ans;
}
void reset(){
	while(!pq1.empty())pq1.pop();
	while(!pq2.empty())pq2.pop();
	z = 0;
}

main(){
	ll ans[100010];
	cin >> t;
	
	for(int k=0;k<t;k++){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> A[i];
			update(A[i],i);
		}
		cin >> q;
		z = 0;
		for(int i=0;i<q;i++){
			cin >> op;
			if(op == 1){
				cin >> from >> to >> k;
				pq1.push(Op(1,from,to,k,z));
				z++;
			}
			if(op == 2){
				cin >> from >> v;
				pq2.push(Op(2,from,v));
			}
		}
		cont = 0;
		while(!pq1.empty()){
			Op temp = pq1.top();
			if(temp.k <= cont){
				ans[temp.num] = query(temp.to) - query(temp.from-1);
				pq1.pop();
			}
			else{
				while(cont < temp.k and !pq2.empty()){
					Op temp1 = pq2.front();
					update(-A[temp1.from],temp1.from);
					update(temp1.v,temp1.from);
					pq2.pop();
					cont++;
				}
			}
		}
		for(int i=0;i<z;i++){
			cout << ans[i] << endl;
		}
	}
}
