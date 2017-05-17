#include <bits/stdc++.h>
using namespace std;

main(){
	double recorde;
	int n,a,b;
	while(cin >> n){
		recorde = -1;
		for(int i=0;i<n;i++){
			cin >> a >> b;
			if((double)b/(double)a > recorde){
				cout << i+1 << endl;
				recorde = (double)b/(double)a;
			}
		}
	
	}

}
