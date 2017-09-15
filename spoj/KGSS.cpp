#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n,q,aux;
ll BIT[1000000];

ll get(int index){
	ll s=0;
	while(index > 0){
		s += BIT[index];
		index -= (index&(-index));
	}
	return s;
}

void update(int index,ll value){
	while(index <= n){
		BIT[index] += value;
		index += index & (-index);
	}
}



main(){
	char e;
	int x,y;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> aux;
		update(i,aux);
	}
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> e >> x >> y;
		if(e=='1'){
			cout << get(y) - get(x-1) << endl;
		}
		else if(e=='0'){
			update(x,-(get(x)-get(x-1)));
			update(x,y);
		}
			//update(x, (y-get(x)-get(x-1)));
	}
	
	
}
