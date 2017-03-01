#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

typedef long long int ll;

double num,mid,ans;
ll p,q,r,s,t,u;


ll bs(double lo,double hi){
	mid = (lo+hi)/2.0;
	if(fabs(hi-lo) < EPS) return -1;
	ans = p*(1.0/pow(M_E,mid))+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*(mid*mid)+u;
	if(ans == 0.0000000000000000) return mid;
	if(num < mid) return bs(lo,mid-0.000000001);
	if(num > mid) return bs(mid+0.000000001,hi);
}


main(){
	
	
	while(cin >> p >> q >> r >> s >> t >> u){
		double aux = bs(0.0000000000,1.0000000000);
		if(aux == -1)
			cout << "No solution\n";
		else
			cout << fixed << setprecision(4) << aux << endl;
	}
}
