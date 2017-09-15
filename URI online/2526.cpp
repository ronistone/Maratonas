#include <bits/stdc++.h>
using namespace std;

int BIT[1000100],n,A[1000100];

int query(int i){
	int s = 0;
	for(;i>0;i-=(i&-i))
		s += BIT[i];
	return s;
}
void update(int i){
	for(;i<=n;i+=(i&-i))
		BIT[i]++;
}


main(){
	int ans;
	while(cin >> n){
		memset(BIT,0,sizeof BIT);
		for(int i=1;i<=n;i++){
			cin >> A[i];
		}
		ans = 0;
		for(int i=n;i>0;i--){
			update(A[i]);
			if(query(A[i]-1) > 1){
				for(int j=n;j>i;j--){
					if(A[j] < A[i])
						ans += query(n)-query(A[j]);
				}
			}
			//ans += query(A[i]-1)-1;
		}
		cout << ans << endl;
	}
}
