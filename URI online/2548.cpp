#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int A[1000],ans;
	
	while(cin >> n >> m){
		for(int i=0;i<n;i++){
			cin >> A[i];
		}
		sort(A,A+n);
		ans = 0;
		while(m--)
			ans += A[n-m-1];
		cout << ans << endl;
	}

}
