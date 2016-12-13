#include <bits/stdc++.h>
using namespace std;

main(){
	int i,j,posi,n,m;

	cin >> n >> m;
	while(n!=0 && m!=0){
		bool falha = false;
		for(i=1,posi = 1;;i = posi){
			i = 2*i-1;
			if(posi == m)
				break;
			if(posi+i>n+1)
				posi-= i;
			else
				posi+=i;

			if(posi<=0 || posi >= n+1){
				falha = true;
				break;
			}
		}
		if(falha){
			cout << "Don't make fun of me!" << endl;
		}
		else
			cout << "Let me try!" << endl;
		cin >> n >> m;
	}
}