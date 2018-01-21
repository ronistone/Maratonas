#include <bits/stdc++.h>
using namespace std;


main(){
	
	int n,m;
	vector<int> A(10100);

	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	
	sort(A.rbegin(),A.rend());
	
	for(int i=0;i<m;i++){
		cout << A[i] << endl;
	}
	
}
