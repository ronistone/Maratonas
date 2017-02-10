#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	ll a,b,c,d;
	
	for(a=1;4 * a<=2000;a++){
		for(b=a;a+3*b<=2000;b++){
				for(c=b;a+b+2*c<=2000;c++){
					ll m = a*b*c;
					ll s = a+b+c;
					
					
					double va = a/100.0,vb = b/100.0, vc = c/100.0, vd = d/100.0;
					if(fabs((a + b + c + d) / 100.0 - (a * b * c * d) / 100000000.0) < 1e-9){
						if(d > c)
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",va,vb,vc,vd);
						else if(d < c and d > b)
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",va,vb,vd,vc);
						else if(d < b and d > a)
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",va,vd,vb,vc);
						else
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",vd,va,vb,vc);
					}
			}
		}
	}
}
