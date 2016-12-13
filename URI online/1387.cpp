#include <bits/stdc++.h>

using namespace std;


main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int l,r;

	while(1){
	cin >> l >> r;
	if(l==r && r==0)
		break;
	
	cout << l+r << endl;
	}
}
