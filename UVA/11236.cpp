#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
typedef long long int ll;
main(){
	
	double a,b,c,d;
	ll i,j,k,l,ans;
	
	for(i=1;4 * i<=2000;i++){
		for(j=i;i+3*j<=2000;j++){
			for(k=j;i+j+2*k<=2000;k++){
				
				ll s = i*j*k;
				ll p = i+j+k;
				
				if(s <=1000000) continue;
				
				l = (1000000 * p) / (s - 1000000);
				
				if( l < k or p+l > 2000) continue;
				
				a = i/100.0;
				b = j/100.0;
				c = k/100.0;
				d = l/100.0;
				if(fabs((p+l)/100.0 - (s*l)/100000000.0) < EPS){
					cout << fixed << setprecision(2) << a << " " << b << " " << c << " " << d << endl;
				}
			}
		}
	}


}
