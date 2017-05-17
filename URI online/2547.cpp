#include <bits/stdc++.h>
using namespace std;


main(){
	int aux,sum,n,hmin,hmax;
	while(cin >> n >> hmin >> hmax){
		sum = 0;
		for(int i=0;i<n;i++){
			cin >> aux;
			if(aux >=hmin and aux <=hmax)
				sum++;
		}
		cout << sum << endl;
	}

}
