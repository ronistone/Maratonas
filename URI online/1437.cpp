#include <bits/stdc++.h>
using namespace std;

main(){
	int n,i,j,ini;

	cin >> n;

	while(n!=0){
		char entrada[n];
		ini =1;
		cin >> entrada;
		for(i=0;i<n;i++){
			if(entrada[i]=='D')
				ini++;
			else
				ini--;
			if(ini>4)
				ini-=4;
			else if(ini<1)
				ini+=4;
		}
		if(ini == 1)
			cout << 'N' << endl;
		else if(ini == 2)
			cout << 'L' << endl;
		else if(ini == 3)
			cout << 'S' << endl;
		else if(ini == 4)
			cout << 'O' << endl;

		cin >> n;
	}
}