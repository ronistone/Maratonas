#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

main(){
	double a,b,c,d;
	
	for(a=0.01;4 * a<=20.0;a+=0.01){
		for(b=a;a+3*b<=20.0;b+=0.01){
				for(c=b;a+b+2*c<=20.0;c+=0.01){
					d = 20.0 - (a + b + c);
					double t = a*b*c*d;
					//if(t >19.9 and t <= 20.1)
					//cout << a << " " << b << " " << c << " " << d << " : " << t << endl;
					if(d < 19.0 and t==20.0){
						
						if(d > c)
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",a,b,c,d);
						else if(d < c and d > b)
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",a,b,d,c);
						else if(d < b and d > a)
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",a,d,b,c);
						else
							printf("%0.2lf %0.2lf %0.2lf %0.2lf\n",d,a,b,c);
					}
			}
		}
	}
}
