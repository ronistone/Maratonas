#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,X,q;
ll A[10002];

ll bs(ll lo,ll hi){
	ll mid = (lo+hi)/2;
	if(lo>hi) return -1;
	if(X > A[mid]) return bs(mid+1,hi);
	if(X < A[mid]) return bs(lo,mid-1);
}


main(){
	int i,c=0;
	ll *ans;
	while(cin >> n >> q and n and q){
			cout << "CASE# " << ++c << ":\n";
			for(i=0;i<n;i++){
				cin >> A[i];
			}
			sort(A,A+n);
			for(i=0;i<q;i++){
				cin >> X;
				ans = lower_bound(A,A+n,X);
				//ans = bs(0,n-1);
				if(*ans!=X)
					cout << X << " not found\n";
				else
					cout << X << " found at " << ans - A+1 << endl;
			}
	}
}
