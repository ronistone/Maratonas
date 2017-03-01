#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	
	ll n,x;
	ll ans;
	ll rep[6][3] = {
		{1,2,3},
		{2,1,3},
		{2,3,1},
		{3,2,1},
		{3,1,2},
		{1,3,2},
	};
	cin >> n >> x;
	ll m = n%6;
	
	if(rep[m][x]==1){
		ans = 0;
	}
	else if(rep[m][x]==2){
		ans = 1;
	}
	else if(rep[m][x]==3){
		ans = 2;
	}

	cout << ans << endl;
}
