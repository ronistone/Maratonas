#include <bits/stdc++.h>
using namespace std;


main(){
	string e;
	int k;
	map<char,bool> M;
	cin >> e;
	cin >> k;
	int rep = 0;
	int diff = 0;
	
	for(int i=0;i<e.size();i++){
		if(!M.count(e[i])){
			M[e[i]] = true;
			diff++;
		}
		else
			rep++;
	}
	
	if(diff < k and rep >= (k-diff)){
		cout << k-diff << endl;
	}
	else if(diff >= k){
		cout << 0 << endl;
	}
	else
		cout << "impossible" << endl;
	
}
