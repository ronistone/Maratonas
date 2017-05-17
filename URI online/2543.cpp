#include <bits/stdc++.h>
using namespace std;


main(){
	int n,m,sum,a,b;
	
	while(cin >> n >> m){
		sum = 0;
		for(int i=0;i<n;i++){
			cin >> a >> b;
			if(a == m and !b)
				sum++;
		}
		cout << sum << endl;
	
	}

}
