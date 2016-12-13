#include <bits/stdc++.h>

using namespace std;

main(){
	long long int primo, n, j, x, i;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> x;
		for(j=2,primo=2;j<ceil(sqrt(x));j++){
			if(x%j==0)
				primo++;		
		}
		if(primo==2)
			cout << "Prime" << endl;
		else
			cout << "Not Prime" << endl;
	}
}