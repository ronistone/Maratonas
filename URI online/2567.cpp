#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int A[2000];
	
	while(cin >> n){
		for(int i=0;i<n;i++)
			cin >> A[i];
		sort(A,A+n);
		int ini = 0;
		int fim = n-1;
		ll ans = 0;
		while(ini < fim){
			ans += A[fim] - A[ini];
			ini++;
			fim--;
		}
		cout << ans << endl;
	}
}
