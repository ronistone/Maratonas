#include <bits/stdc++.h>
using namespace std;

main(){
	int n,o,h,s,p,c,i,j;
	while(cin >> n >> o >> h >> s){
		int menor = INT_MAX;
		for(i=0;i<h;i++){
			bool falha = false, cama = false;
			cin >> p;
			if(o<p*n)
				falha = true;
			for(j=0;j<s;j++){
				cin >> c;
				if(c>=n)
					cama = true;
			}
			if(!falha and cama){
				if(menor> p*n)
					menor = p*n;
			}
				
		}
		if(menor!=INT_MAX)
			cout << menor << endl;
		else
			cout << "stay home" << endl;
	}
}
