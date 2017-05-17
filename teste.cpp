#include <bits/stdc++.h>
using namespace std;

main(){
	int n,z;
	string e;
	int mask;
	 
	cin >> n;
	
	for(int k=0;k<n;k++){		
		cin >> z >> e;
		for(mask=0; mask< (1 << z);mask++){
			for(int i=0;i<z;i++){
				if(mask & (1 << i))
					cout << e[i];
			}
			cout << endl;
		}
	}	
}
