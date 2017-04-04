#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-6

typedef long long int ll;


main(){
	int p,q,r,s,t,u;
	
	
	while(cin >> p >> q >> r >> s >> t >> u){
		double ini= 0.000000,fim = 1.000000, mid = 0.500000;
		bool achou = false;
		
		while(ini<=fim){
			double ans = p*exp(-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*(mid*mid)+u;
			if(fabs(ans) <= EPS){
				cout << fixed << setprecision(4) << mid << endl;
				achou = true;
				break;
			}
			else if(ans < EPS)
				fim = mid - 0.000000001;
			else
				ini = mid + 0.000000001;
			mid = (ini+fim)/2;
		}
		if(!achou)
			cout << "No solution\n";
	}


}
