#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,aux;
	vector<int> q;
	
	cin >> n;
	
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			cin >> aux;
			q.push_back(aux);
		}
		sort(q.begin(),q.end());
		cout << "Case " << i+1 << ": " << q[1] << endl;
		q.clear();
	}
}