#include <bits/stdc++.h>
using namespace std;

main(){
	int n,low=10101010,high=-10,lowi,highi;
	int A[1000];
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> A[i];
		if(A[i] <= low){
			low = A[i];
			lowi = i;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(A[i] >= high){
			high = A[i];
			highi = i;
		}
	}
	cout << (((highi)) + ((n - lowi)-1)) + (highi > lowi? -1:0) << endl;

}
