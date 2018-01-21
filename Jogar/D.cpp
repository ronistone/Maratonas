#include <bits/stdc++.h>
using namespace std;


main(){
	double r,h1,h2;
	cin >> r >> h1 >> h2;
	
	double v1 = M_PI * (r*r) * h2;
	
	cout << fixed << setprecision(3) << v1 - (M_PI *(r*r)*h1) << endl;

}
