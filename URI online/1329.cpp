#include <bits/stdc++.h>

using namespace std;

main(){
	int n=-1,i,joao,maria;
	int v;


	while(true){
		cin >> n;
		if(n==0)
			break;
		joao = 0;
		maria = 0;
		for(i=0;i<n;i++){
			cin >> v;
			if(v == 0)
				maria++;
			else if(v == 1)
				joao++;
		}
		cout << "Mary won " << maria <<" times and John won " << joao << " times" << endl;
	}


}