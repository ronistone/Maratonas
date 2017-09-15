#include <bits/stdc++.h>
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char A[] = "ABCD";
	string ans;
	long long int n;
	while(cin >> n and n){
		ans.clear();
		n*=n;
		while(n!=0){
			ans = A[n%4] + ans;
			n /= 4;
		}
		cout << ans << endl;
	}

}
