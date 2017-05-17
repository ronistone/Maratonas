#include <bits/stdc++.h>
using namespace std;


main(){
	int n;
	int a,b,sum1,sum2;
	while(cin >> n){
		sum1 = 0;
		sum2 = 0;
		for(int i=0;i<n;i++){
			cin >> a >> b;
			sum1 += (a*b);
			sum2 += b*100;
		}
		cout << fixed << setprecision(4) << (double)sum1/(double)sum2 << endl;
	}
}
