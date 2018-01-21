#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;


/*ll BIT[100100];

ll query(int i){
	
	ll ans = 0;
	
	for( ; i > 0; i-=(i & (-i))){
		ans += BIT[i];
	}
	return ans;
}
void update(int i, int u){
	
	for( ; i <= n; i += (i & (-i))){
		BIT[i] += u;
	}
}*/


int main(){
	int n,E[100100], D[100100], e, d;
	string R;
	cin >> n;
	
	R = "";
	for(int i=0;i<n;i++){
		cin >> E[i];
		R += "-";
	}
	for(int i=0;i<n;i++){
		cin >> D[i];
	}
	e = E[0];
	d = D[n-1];
	for(int i=0;i<=n/2;i++){
		R[i] = E[i+1] - E[i] ? '0':'1';
		//R[n-1-i] = D[n-i-2] - D[n-1-i]? '1':'0';
		e = E[i+1];
		d = D[i-n-1];
		//cout << R << endl;
	}
	for(int i=n-1;i>=n/2;i--){
		R[i] = D[i-1] - D[i]? '0':'1';
	}
	cout << R << endl;
	//cout << string(R.rbegin(),R.rend()) << endl;
	return 0;
}
