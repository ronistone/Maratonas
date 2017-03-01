#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll BIT[100100];
int n;

inline void update(ll index){
	
	for(;index<=n;index += index  &(-index))
		BIT[index] += 1;
}
inline ll query(ll index){
	ll ans =0;
	for(;index>0;index -= index & (-index))
		ans += BIT[index];
	return ans;
}


main(){
	vector<ll> num;
	scanf("%d",&n);
	ll ans = 0,aux;
	for(int i=1;i<=n;i++){
		scanf("%lld",&aux);
		num.push_back(aux);
	}
	for(int i=num.size()-1;i>=0;i--){
		update(num[i]);
		ans += query(num[i]-1);
	}
	printf("%lld\n",ans);

}
