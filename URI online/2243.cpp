#include <bits/stdc++.h>
using namespace std;

int H[60000], E[60000], D[60000];

main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> H[i];
	}
	if(H[0])
		E[0] = 1;
	if(H[n-1])
		D[n-1] = 1;
	for(int i=1;i<n;i++){
		E[i] = min(i+1,E[i-1]) < H[i] ? min(i+1,E[i-1])+1 : min(H[i],min(i+1,E[i-1]));
	}
	for(int i=n-2;i>=0;i--){
		D[i] = min((n - i), D[i+1]) < H[i] ? min((n - i), D[i+1])+1 : min(H[i],min((n - i), D[i+1]));
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, min(E[i],D[i]));
	}
	cout << ans << endl;
}
