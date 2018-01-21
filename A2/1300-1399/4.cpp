#include <bits/stdc++.h>
using namespace std;

int A[] = {1,2,3,4,5,6,7,8,9,10,11,10,10,10};


main(){

	int n,ans=0;
	cin >> n;
	
	
	for(int i=0;i<14;i++){
		for(int j=i+1;j<14;j++){
			if(A[i]+A[j]==n)
				ans++;
		}
	}
	cout << ans << endl;
	

}
