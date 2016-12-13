#include <bits/stdc++.h>
using namespace std;

main(){
	int n,z,i,j,k;
	map<int,bool> v;
	vector<int> vi;
	
	cin >> n >> z;
	
	for(i=0;i<z;i++){
		cin >> k;
		v[k] = true;
	}
	for(i=0;i<n;i++){
		cin >> k;
		vi.push_back(k);
	}
//	sort(vi.begin(),vi.end());
	
	for(i=0;i<vi.size();i++){
		cout << !v[vi[i]] << endl;
		v[vi[i]] = true;
	}
	
}
