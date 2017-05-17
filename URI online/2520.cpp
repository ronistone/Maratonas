#include <bits/stdc++.h>
using namespace std;


main(){
	
	int n,m,aux;
	int xi,yi,xf,yf;
	
	while(cin >> n >> m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> aux;
				if(aux == 1){
					xi = i;
					yi = j;
				}
				else if(aux == 2){
					xf = i;
					yf = j;
				}
			}
		}
		cout << (abs(xi-xf)+abs(yi-yf)) << endl;
	}

}
