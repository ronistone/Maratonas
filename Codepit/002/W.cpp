#include <bits/stdc++.h>
using namespace std;

main(){
	int n,q,aux,i,j,count =0;
	std::vector<int> v;
	while(cin >> n >> q and n and q){
		count++;
		for(i=0;i<n;i++){
			cin >> aux;
			v.push_back(aux);
		}
		sort(v.begin(),v.end());
		cout << "CASE# " << count << ":" << endl;
		for(i=0;i<q;i++){
			bool achou = false;
			cin >> aux;
			for(j=0;j<n;j++){
				if(aux == v[j]){
					cout << aux << " found at " << j+1 << endl;
					achou = true;
					break;
				}
			}
			if(not achou)
				cout << aux << " not found" << endl;
		}
		v.clear();
	}
}