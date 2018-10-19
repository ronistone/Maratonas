#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-8

main(){
	double x,y;

	cin >> x >> y;
	
	double b = x*log10(y);
	double a = y*log10(x);
	
	if(fabs(a-b) < EPS)
		cout << "=" << endl;
	else if(a < b)
		cout << "<" << endl;
	else
		cout << ">" << endl;

}
