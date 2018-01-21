#include <bits/stdc++.h>
using namespace std;

#define EPS 10e-11

main(){
	double n;
	cin >> n;
	
	double ans = log2(n);
	
	if(fabs(floor(ans) - ans) < EPS)
		cout << (int)ans << endl;
	else
		cout << -1 << endl;
	//cout << (int) (log(n) <= EPS? log(n):-1) << endl;

}
