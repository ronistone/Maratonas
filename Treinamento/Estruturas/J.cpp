#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef struct no{
	char op;
	ll v;
	no(char op_,ll v_): op(op_),v(v_){}
}Op;
ll n;
ll BIT[1000000],cont;
set<ll> S;
unordered_map<ll,ll> in,out;

void update(ll value,ll index){
	for(;index<=n;index += index & (-index))
		BIT[index] += value;
}
ll query(ll index){
	ll ans = 0;
	for(;index > 0; index -= index & (-index))
		ans += BIT[index];
		
	return ans;
}
ll Kesimo(ll k){
	int ini = 1;
	int fim = n;
	int mid = (ini+fim)/2;
	
	while(ini <= fim){
		ll ans = query(mid);
		//cout << "BB: " << mid << "  --   " << ans << " ===== " << k << endl;
		if(ans==k and ans-query(mid-1)==1) return mid;
		else if(ans >= k) fim = mid-1;
		else if(ans < k) ini = mid+1;
		mid = (ini+fim)/2;
	}
	//cout << "DEU RUIM\n";
}


main(){
	vector<Op> o;
	char a;
	ll v,i;
	set<ll>::iterator it;
	while(scanf("%lld",&n)!=EOF){
		in.clear();
		out.clear();
		S.clear();
		o.clear();
		for(i=0;i<n;i++){
			getchar();
			scanf("%c %lld",&a, &v);
			o.push_back(Op(a,v));
			S.insert(v);
		}
		n = S.size();
		for(i=1,it = S.begin();it!=S.end();it++,i++){
			in[i] = *it;
			out[*it] = i;
		}
		cont = 0;
		for(i=0;i<o.size();i++){
			if(o[i].op=='I'){
				if(query(out[o[i].v]) - query(out[o[i].v]-1) == 0){
					update(1,out[o[i].v]);
					cont++;
				}
			}
			else if(o[i].op=='D'){
				if(query(out[o[i].v]) - query(out[o[i].v]-1) == 1){
					update(-1,out[o[i].v]);
					cont--;
				}
			}
			else if(o[i].op=='C'){
				printf("%lld\n",query(out[o[i].v]-1));
			}
			else  if(o[i].op=='K'){
				if(o[i].v > cont)
					printf("invalid\n");
				else{
					printf("%lld\n",in[Kesimo(o[i].v)]);
				}
			}
		}
		
	
	}

}
