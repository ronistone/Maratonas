#include <bits/stdc++.h>
using namespace std;

main(){
	int i,j,n,f,p,cont;

	while(cin >> n and n!=0){
		f = p = 0;
		cont = 1;
		while(n > 0){
			p ++;
			n --;
			for(i = 1;i<=cont;i++){
				f++;
				if(n-1 < 0){	
					if(p-1<0)
						break;
					else{	
						p--;
					}
				}
				else
					n--;
			}
			cont++;
		}
		cout << f << " " << p << endl;
	}
}