#include <bits/stdc++.h>
using namespace std;

main(){
	
	int n,q,aux;
	vector<int> A;
	while(cin >> n >> q){
		for(int i=0;i<n;i++){
			cin >> aux;
			A.push_back(aux);
		}
		sort(A.rbegin(),A.rend());
		for(int i=0;i<q;i++){
			cin >> aux;
			cout << A[aux-1] << endl;
		}
		A.clear();
	}	
	
}
