#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,i;
	ll A[10000];
	ll sum,ans;
	while(cin >> n and n){
		sum=0,ans=0;
		for(i=0;i<n;i++){
			cin >> A[i];
			sum+=A[i];
			ans = max(sum,ans);
			if(sum<0) sum = 0;
		}
		if(ans == 0)
			cout << "Losing streak.\n";
		else
			cout << "The maximum winning streak is " << ans << "." << endl;
	}
}
